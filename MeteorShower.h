#pragma once
#include "ExternalObject.h"

class MeteorShower : public ExternalObject {
public:
	void interact(CommandCenter& center, Module& module) override;
};