#include <iostream>
#include "EnvironmentProxy.h"
#include "Module.h"

EnvironmentProxy::EnvironmentProxy(std::shared_ptr<Environment> realEnv) : realEnvironment_(realEnv) {
}
void EnvironmentProxy::applyEffect(Module& module) {
    if (module.getIsBlocked()) {
        std::cout << "[Proxy] Module " << module.getName() << " is blocked. Effect skipped.\n";
        return;
    }
    int id = module.getID();
    auto it = effectCache_.find(id);
    if (it != effectCache_.end()) {
        std::cout << "[Proxy] Cache hit for module " << module.getName()
            << ". Last effect: " << it->second << std::endl;
    }
    if (module.getType().find("Physics") != std::string::npos ||
        module.getType().find("Biology") != std::string::npos) {
        std::cout << "[Proxy] Research module detected. Additional check...\n";
    }
    realEnvironment_->applyEffect(module);

    effectCache_[id] = realEnvironment_->getName();
}
std::string EnvironmentProxy::getName() const {
    return realEnvironment_->getName() + " (Proxy)";
}
double EnvironmentProxy::getEnergyModifier() const {
    return realEnvironment_->getEnergyModifier();
}
double EnvironmentProxy::getDamageModifier() const {
    return realEnvironment_->getDamageModifier();
}