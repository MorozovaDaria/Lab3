#include "CargoContainer.h"
#include "CommandCenter.h"
#include "Module.h"
#include "ResourcePackage.h"

void CargoContainer::interact(CommandCenter& center, Module& module) {
    ResourcePackage package(200.0, 100.0, 10);
    center + package;
}