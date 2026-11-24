#include "StandardModuleFactory.h"
#include "LoggingProxy.h"
#include <string>

Module* StandardModuleFactory::createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new CrewCabin(name, effectiveness, durability, energy, capacity);
}
Module* StandardModuleFactory::createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new SolarModule(name, effectiveness, durability, energy, capacity);
}
Module* StandardModuleFactory::createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) {
	return new BiologyLab(name, effectiveness, durability, energy, capacity);
}


std::unique_ptr<Module> StandardModuleFactory::createModule(const std::string& type, const std::string& name) {
    if (type == "solar" || type == "energy") {
        return std::unique_ptr<Module>(createEnergyModule(name, 100, 100, 10, 100));
    }
    else if (type == "crew" || type == "apartment") {
        return std::unique_ptr<Module>(createApartmentModule(name, 100, 100, 5, 100));
    }
    else if (type == "biology" || type == "research") {
        return std::unique_ptr<Module>(createResearchModule(name, 100, 100, 20, 100));
    }

    LoggingProxy::log("Factory", "Неизвестный тип модуля: " + type);
    return nullptr;
}