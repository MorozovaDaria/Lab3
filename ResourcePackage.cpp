#include "ResourcePackage.h"

ResourcePackage::ResourcePackage(double energy, double oxygen, int safetyLevel) : energy_(energy), oxygen_(oxygen), safetyLevel_(safetyLevel) {

}
double ResourcePackage::getEnergy() const {
	return energy_;
}
double ResourcePackage::getOxygen() const {
	return oxygen_;
}
int ResourcePackage::getSafetyLevel() const {
	return safetyLevel_;
}