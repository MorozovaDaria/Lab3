#include "EnergyModuleStrategy.h"
#include "Module.h"
#include "Damage.h"
#include "Types.h"
#include <iostream>

void EnergyModuleStrategy::apply(Module& module) {
    Damage dmg(15.0, DamageType::Energy);
    module - dmg;
    std::cout << "[EnergyStrategy] Applied energy stress to " << module.getName() << std::endl;
}