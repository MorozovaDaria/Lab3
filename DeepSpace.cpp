#include "DeepSpace.h"
#include "Module.h"
#include "EnergyModuleStrategy.h"
#include "CrewModuleStrategy.h"
#include "ResearchModuleStrategy.h"
#include <iostream>
#include <memory>

void DeepSpace::applyEffect(Module& module) {
    std::unique_ptr<IInteractionStrategy> strategy;
    std::string type = module.getType();
    if (type.find("Solar") != std::string::npos || type.find("Reactor") != std::string::npos) {
        strategy = std::make_unique<EnergyModuleStrategy>();
    }
    else if (type.find("Crew") != std::string::npos || type.find("Medical") != std::string::npos) {
        strategy = std::make_unique<CrewModuleStrategy>();
    }
    else {
        strategy = std::make_unique<ResearchModuleStrategy>();
    }
    if (strategy) {
        strategy->apply(module);
    }
}
std::string DeepSpace::getName() const {
    return "DeepSpace";
}
double DeepSpace::getEnergyModifier() const {
    return 1.5;
}
double DeepSpace::getDamageModifier() const {
    return 1.0;
}