#pragma once

class EnergySystem {
private:
    double totalEnergy_;
    double distribution_;

public:
    EnergySystem(double initialEnergy = 1000.0);
    ~EnergySystem() = default;

    void distribute(double amount);
    void consume(double amount);
    double getAvailable() const;

    void setTotalEnergy(double amount);
    void setDistribution(double amount);
    double getTotalEnergy() const;
    double getDistribution() const;
};