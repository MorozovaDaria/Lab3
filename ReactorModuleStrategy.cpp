#include "ReactorModuleStrategy.h"
#include "Module.h"
#include "Damage.h"
#include "Types.h"
#include <iostream>

void ReactorModuleStrategy::apply(Module& module) {
    Damage dmg(20.0, DamageType::Energy);
    module - dmg;
    std::cout << "[ReactorStrategy] Critical stress on " << module.getName() << std::endl;
}