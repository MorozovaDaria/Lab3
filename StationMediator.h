#pragma once
#include <memory>

class CommandCenter;
class EnergySystem;
class EnvironmentSystem;

class StationMediator {
private:
    std::shared_ptr<CommandCenter> commandCenter_;
    std::shared_ptr<EnergySystem> energySystem_;
    std::shared_ptr<EnvironmentSystem> environmentSystem_;

public:
    StationMediator();
    ~StationMediator() = default;

    void setCommandCenter(std::shared_ptr<CommandCenter> center);
    void setEnergySystem(std::shared_ptr<EnergySystem> system);
    void setEnvironmentSystem(std::shared_ptr<EnvironmentSystem> system);

    std::shared_ptr<CommandCenter> getCommandCenter() const;
    std::shared_ptr<EnergySystem> getEnergySystem() const;
    std::shared_ptr<EnvironmentSystem> getEnvironmentSystem() const;

    bool requestEnergy(int moduleIndex, double amount);   
    void notifyDamage(int moduleIndex);
    void notifyActivation(int moduleIndex);
    void notifyResearchComplete(int moduleIndex);
    void distributeResources();
};