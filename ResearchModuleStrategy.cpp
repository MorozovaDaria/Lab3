#include "ResearchModuleStrategy.h"
#include "Module.h"
#include "Damage.h"
#include "Types.h"
#include <iostream>

void ResearchModuleStrategy::apply(Module& module) {
    Damage dmg(12.0, DamageType::Radiation);
    module - dmg;
    std::cout << "[ResearchStrategy] Applied radiation to " << module.getName() << std::endl;
}