#pragma once
#include "ExternalObject.h"

class CargoContainer : public ExternalObject {
public:
	void interact(CommandCenter& center, Module& module) override;
};