#include "SpaceAnomaly.h"
#include "CommandCenter.h"
#include "Module.h"
#include <cstdlib>

void SpaceAnomaly::interact(CommandCenter& center, Module& module) {
    int effect = rand() % 3;
    if (effect == 0) {
        module * 1.5;
    }
    else if (effect == 1) {
        module * 0.7;
    }
    else {
        module.setBlocked(true);
    }
}