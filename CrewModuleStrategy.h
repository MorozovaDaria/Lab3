#pragma once
#include "IInteractionStrategy.h"

class CrewModuleStrategy : public IInteractionStrategy {
public:
	void apply(Module& module) override;
};