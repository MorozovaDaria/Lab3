#pragma once

class Module;

class IInteractionStrategy {
public:
	virtual void apply(Module&) = 0;
	virtual ~IInteractionStrategy() = default;
};	