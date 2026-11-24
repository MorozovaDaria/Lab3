#include "StartResearchCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "LoggingProxy.h"

StartResearchCommand::StartResearchCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex)
    : Command(mediator), moduleIndex_(moduleIndex) {
}

void StartResearchCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    Module* module = center->getModuleByIndex(moduleIndex_);
    if (!module) {
        LoggingProxy::log("Command", "Ошибка: модуль не найден.");
        return;
    }

    if (!module->getIsActive()) {
        LoggingProxy::log("Command", "Ошибка: модуль [" + module->getName() + "] выключен. Сначала активируйте его.");
        return;
    }

    if (module->getType() != "Research" && module->getType() != "BiologyLab" && module->getType() != "PhysicsLab") {
        LoggingProxy::log("Command", "Ошибка: модуль [" + module->getName() + "] не является исследовательским.");
        return;
    }

    double energyCost = 50.0;

    if (module->requestEnergy(energyCost)) {
        LoggingProxy::log("Command", "Исследование в модуле [" + module->getName() + "] запущено. Потрачено энергии: " + std::to_string(energyCost));
        mediator_->notifyResearchComplete(moduleIndex_);
    }
    else {
        LoggingProxy::log("Command", "Ошибка: недостаточно энергии для запуска исследования.");
    }
}