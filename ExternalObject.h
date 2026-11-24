#pragma once
#include "Types.h"

class Module;
class CommandCenter;

class ExternalObject {
private:
	ExternalObjectType type_;
	int strength_;
public:
	virtual void interact(CommandCenter& center, Module& module) = 0;
	virtual ~ExternalObject() = default;
};