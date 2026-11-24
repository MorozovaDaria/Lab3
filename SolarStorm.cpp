#include "SolarStorm.h"
#include "CommandCenter.h"
#include "Module.h"
#include "Damage.h"
#include "Types.h"

void SolarStorm::interact(CommandCenter& center, Module& module) {
    Damage dmg(25.0, DamageType::Radiation);
    module - dmg;
}