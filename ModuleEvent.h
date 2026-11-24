#pragma once
#include <string>
#include "Types.h"

class ModuleEvent {
private:
	EventType type_;
	int moduleID_;
	int damage_;
	int timeStamp_;
public:
	ModuleEvent(EventType type, int moduleID, int damage, int timeStamp);
	EventType getType() const;
	int getModuleID() const;
	int getDamage() const;
	int getTimeStamp() const;
};