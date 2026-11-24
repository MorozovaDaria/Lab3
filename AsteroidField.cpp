#include "AsteroidField.h"
#include "Module.h"
#include "ResearchModuleStrategy.h"
#include <iostream>
#include <memory>

void AsteroidField::applyEffect(Module& module) {
    std::string type = module.getType();
    if (type.find("Biology") != std::string::npos || type.find("Physics") != std::string::npos) {
        module.setBlocked(true);
        std::cout << "[AsteroidField] Research module " << module.getName() << " is blocked" << std::endl;
    }
    else {
        std::unique_ptr<IInteractionStrategy> strategy = std::make_unique<ResearchModuleStrategy>();
        strategy->apply(module);
    }
}
std::string AsteroidField::getName() const {
    return "AsteroidField";
}
double AsteroidField::getEnergyModifier() const {
    return 1.0;
}
double AsteroidField::getDamageModifier() const {
    return 1.2;
}
