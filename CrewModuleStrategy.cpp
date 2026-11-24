#include "CrewModuleStrategy.h"
#include "Module.h"
#include "Damage.h"
#include "Types.h"
#include <iostream>

void CrewModuleStrategy::apply(Module& module) {
    Damage dmg(8.0, DamageType::Physical);
    module - dmg;
    std::cout << "[CrewStrategy] Applied pressure effect to " << module.getName() << std::endl;
}