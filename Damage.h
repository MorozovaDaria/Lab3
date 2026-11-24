#pragma once
#include "Types.h"

class Damage {
private:
	double amount_;
	DamageType type_;
public:
	Damage(double amount, DamageType type);
	double getAmount() const;
	DamageType getType() const;
};