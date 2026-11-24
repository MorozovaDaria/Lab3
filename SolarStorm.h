#pragma once
#include "ExternalObject.h"

class SolarStorm : public ExternalObject {
public:
	void interact(CommandCenter& center, Module& module) override;
};