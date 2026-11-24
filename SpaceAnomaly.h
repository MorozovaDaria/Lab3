#pragma once
#include "ExternalObject.h"

class SpaceAnomaly : public ExternalObject {
public:
	void interact(CommandCenter& center, Module& module) override;
};