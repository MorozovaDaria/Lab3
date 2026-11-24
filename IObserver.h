#pragma once
#include "ModuleEvent.h"

class IObserver {
public:
	virtual void onModuleEvent(const ModuleEvent& event) = 0;
	virtual ~IObserver() = default;
};