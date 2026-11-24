#include "RepairModuleCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "LoggingProxy.h"

RepairModuleCommand::RepairModuleCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex)
    : Command(mediator), moduleIndex_(moduleIndex) {
}

void RepairModuleCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    Module* module = center->getModuleByIndex(moduleIndex_);

    if (module) {
        double repairCost = 20.0;

        if (module->requestEnergy(repairCost)) {
            module->getDurability().repair(50);
            LoggingProxy::log("Command", "Модуль [" + module->getName() + "] отремонтирован. Потрачено энергии: " + std::to_string(repairCost));
        }
        else {
            LoggingProxy::log("Command", "Ошибка: недостаточно энергии для ремонта модуля [" + module->getName() + "].");
        }
    }
    else {
        LoggingProxy::log("Command", "Ошибка: модуль не найден.");
    }
}