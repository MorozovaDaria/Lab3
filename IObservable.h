#pragma once
#include "ModuleEvent.h"
#include "IObserver.h"
#include <vector>

class IObservable {
protected:
	std::vector<IObserver*> observers_;
public:
	virtual void subscribe(IObserver*) = 0;
	virtual void unsubscribe(IObserver*) = 0;
	virtual void notify(const ModuleEvent&) = 0;
	virtual ~IObservable() = default;
};