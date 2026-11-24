#include "Damage.h"

Damage::Damage(double amount, DamageType type) : amount_(amount), type_(type) {

}
double Damage::getAmount() const {
	return amount_;
}
DamageType Damage::getType() const {
	return type_;
}