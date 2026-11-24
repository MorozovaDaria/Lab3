#include "StationMediator.h"
#include "CommandCenter.h"
#include "EnergySystem.h"
#include "EnvironmentSystem.h"
#include "Module.h"
#include "LoggingProxy.h"

StationMediator::StationMediator() = default;

void StationMediator::setCommandCenter(std::shared_ptr<CommandCenter> center) {
    commandCenter_ = center;
}

void StationMediator::setEnergySystem(std::shared_ptr<EnergySystem> system) {
    energySystem_ = system;
}

void StationMediator::setEnvironmentSystem(std::shared_ptr<EnvironmentSystem> system) {
    environmentSystem_ = system;
}

std::shared_ptr<CommandCenter> StationMediator::getCommandCenter() const {
    return commandCenter_;
}

std::shared_ptr<EnergySystem> StationMediator::getEnergySystem() const {
    return energySystem_;
}

std::shared_ptr<EnvironmentSystem> StationMediator::getEnvironmentSystem() const {
    return environmentSystem_;
}

bool StationMediator::requestEnergy(int moduleIndex, double amount) {
    if (!commandCenter_ || !energySystem_) return false;

    LoggingProxy::log("Mediator", "Модуль " + std::to_string(moduleIndex) + " запрашивает энергию: " + std::to_string(amount));

    if (!commandCenter_->spendEnergy(amount)) {
        LoggingProxy::log("Mediator", "Недостаточно энергии на станции для модуля " + std::to_string(moduleIndex));
        return false;
    }

    energySystem_->consume(amount);

    LoggingProxy::log("Mediator", "Энергия выделена модулю " + std::to_string(moduleIndex));
    return true;
}

void StationMediator::notifyDamage(int moduleIndex) {
    if (!commandCenter_) return;

    LoggingProxy::log("Mediator", "Модуль " + std::to_string(moduleIndex) + " получил повреждения!");

    if (environmentSystem_) {
        environmentSystem_->applyEffects();
    }
}

void StationMediator::notifyActivation(int moduleIndex) {
    if (!commandCenter_) return;

    Module* module = commandCenter_->getModuleByIndex(moduleIndex);
    if (module) {
        LoggingProxy::log("Mediator", "Модуль [" + module->getName() + "] изменил статус активности.");
    }
}

void StationMediator::notifyResearchComplete(int moduleIndex) {
    if (!commandCenter_) return;

    LoggingProxy::log("Mediator", "Исследование в модуле " + std::to_string(moduleIndex) + " завершено.");
    commandCenter_->setSafetyLevel(commandCenter_->getSafetyLevel() + 5);
}

void StationMediator::distributeResources() {
    if (!commandCenter_ || !energySystem_) return;

    LoggingProxy::log("Mediator", "Перераспределение ресурсов станции...");
    double available = energySystem_->getAvailable();
    commandCenter_->restoreEnergy(available * 0.1);
}