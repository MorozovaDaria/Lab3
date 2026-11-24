#pragma once
#include "ModuleFactory.h"
#include "MedicalCabin.h"
#include "ReactorModule.h" 
#include "PhysicsLab.h"

class AdvancedModuleFactory : public ModuleFactory {
public:
	virtual Module* createApartmentModule(std::string name, int effectiveness, int durability, int energy, int capacity) override;
	virtual Module* createEnergyModule(std::string name, int effectiveness, int durability, int energy, int capacity) override;
	virtual Module* createResearchModule(std::string name, int effectiveness, int durability, int energy, int capacity) override;

	virtual std::unique_ptr<Module> createModule(const std::string& type, const std::string& name) override;
};