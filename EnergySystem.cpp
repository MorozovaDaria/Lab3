#include "EnergySystem.h"
#include "LoggingProxy.h"

EnergySystem::EnergySystem(double initialEnergy) : totalEnergy_(initialEnergy), distribution_(0.0) {

}

void EnergySystem::distribute(double amount) {
    if (amount <= 0.0) return;

    distribution_ += amount;
    if (distribution_ > totalEnergy_) {
        distribution_ = totalEnergy_;
    }
    LoggingProxy::log("EnergySystem", "Распределено энергии: " + std::to_string(amount));
}

void EnergySystem::consume(double amount) {
    if (amount <= 0.0) return;

    totalEnergy_ -= amount;
    if (totalEnergy_ < 0.0) {
        totalEnergy_ = 0.0;
    }
    LoggingProxy::log("EnergySystem", "Израсходовано энергии: " + std::to_string(amount) + ". Остаток: " + std::to_string(totalEnergy_));
}

double EnergySystem::getAvailable() const {
    return totalEnergy_ - distribution_;
}

void EnergySystem::setTotalEnergy(double amount) {
    totalEnergy_ = amount;
    if (totalEnergy_ < 0.0) totalEnergy_ = 0.0;
}

void EnergySystem::setDistribution(double amount) {
    distribution_ = amount;
    if (distribution_ < 0.0) distribution_ = 0.0;
    if (distribution_ > totalEnergy_) distribution_ = totalEnergy_;
}

double EnergySystem::getTotalEnergy() const {
    return totalEnergy_;
}

double EnergySystem::getDistribution() const {
    return distribution_;
}