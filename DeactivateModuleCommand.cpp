#include "DeactivateModuleCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "LoggingProxy.h"

DeactivateModuleCommand::DeactivateModuleCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex)
    : Command(mediator), moduleIndex_(moduleIndex) {
}

void DeactivateModuleCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    Module* module = center->getModuleByIndex(moduleIndex_);

    if (module) {
        module->deactivate();  // внутри уже уведомляет посредника
        LoggingProxy::log("Command", "Модуль [" + module->getName() + "] деактивирован.");
    }
    else {
        LoggingProxy::log("Command", "Ошибка: модуль с индексом " + std::to_string(moduleIndex_) + " не найден.");
    }
}