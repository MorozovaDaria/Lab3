#pragma once
#include "Environment.h"

class AsteroidField : public Environment {
public:
    void applyEffect(Module& module) override;
    std::string getName() const override;
    double getEnergyModifier() const override;
    double getDamageModifier() const override;
};