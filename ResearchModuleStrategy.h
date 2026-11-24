#pragma once
#include "IInteractionStrategy.h"

class ResearchModuleStrategy : public IInteractionStrategy {
public:
	void apply(Module& module) override;
}; 
