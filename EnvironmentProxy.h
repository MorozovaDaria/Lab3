#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "Environment.h"

class Module;

class EnvironmentProxy : public Environment {
private:
    std::shared_ptr<Environment> realEnvironment_;
    std::unordered_map<int, std::string> effectCache_;

public:
    EnvironmentProxy(std::shared_ptr<Environment> realEnv);
    void applyEffect(Module& module) override;
    std::string getName() const override;
    double getEnergyModifier() const override;
    double getDamageModifier() const override;
};