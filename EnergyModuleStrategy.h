#pragma once
#include "IInteractionStrategy.h"

class EnergyModuleStrategy : public IInteractionStrategy {
public:
	void apply(Module& module) override;
};