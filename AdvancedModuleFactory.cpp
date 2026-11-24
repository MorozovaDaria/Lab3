#include "AdvancedModuleFactory.h"
#include "LoggingProxy.h"
#include <string>

Module* AdvancedModuleFactory::createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new MedicalCabin(name, effectiveness, durability, energy, capacity);
}
Module* AdvancedModuleFactory::createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new ReactorModule(name, effectiveness, durability, energy, capacity);
}
Module* AdvancedModuleFactory::createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new PhysicsLab(name, effectiveness, durability, energy, capacity);
}


std::unique_ptr<Module> AdvancedModuleFactory::createModule(const std::string& type, const std::string& name) {
    if (type == "reactor") {
        return std::unique_ptr<Module>(createEnergyModule(name, 150, 120, 15, 150));
    }
    else if (type == "medical") {
        return std::unique_ptr<Module>(createApartmentModule(name, 120, 80, 8, 120));
    }
    else if (type == "physics") {
        return std::unique_ptr<Module>(createResearchModule(name, 150, 90, 25, 150));
    }

    LoggingProxy::log("Factory", "Неизвестный продвинутый тип модуля: " + type);
    return nullptr;
}