#include "MeteorShower.h"
#include "CommandCenter.h"
#include "Module.h"
#include "Damage.h"
#include "Types.h"

void MeteorShower::interact(CommandCenter& center, Module& module) {
    Damage dmg(30.0, DamageType::Physical);
    module - dmg;
}