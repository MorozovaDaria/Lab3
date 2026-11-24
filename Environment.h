#pragma once
#include <string>

class Module;

class Environment {
public:
	virtual void applyEffect(Module&) = 0;
	virtual std::string getName() const = 0;
	virtual double getEnergyModifier() const = 0;
	virtual double getDamageModifier() const = 0;
	virtual ~Environment() = default;
};