#include "EarthOrbit.h"
#include "Module.h"
#include <iostream>

void EarthOrbit::applyEffect(Module& module) {
    std::cout << "[EarthOrbit] Mild effect on module " << module.getName() << std::endl;
}
std::string EarthOrbit::getName() const {
    return "EarthOrbit";
}
double EarthOrbit::getEnergyModifier() const {
    return 1.0;
}
double EarthOrbit::getDamageModifier() const {
    return 1.0;
}