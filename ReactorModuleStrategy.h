#pragma once
#include "IInteractionStrategy.h"

class ReactorModuleStrategy : public IInteractionStrategy {
public:
	void apply(Module& module) override;
}; 
