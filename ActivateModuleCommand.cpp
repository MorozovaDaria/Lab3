#include "ActivateModuleCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "LoggingProxy.h"

ActivateModuleCommand::ActivateModuleCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex)
    : Command(mediator), moduleIndex_(moduleIndex) {
}

void ActivateModuleCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    Module* module = center->getModuleByIndex(moduleIndex_);

    if (module) {
        module->activate();   
        LoggingProxy::log("Command", "Модуль [" + module->getName() + "] активирован.");
    }
    else {
        LoggingProxy::log("Command", "Ошибка: модуль с индексом " + std::to_string(moduleIndex_) + " не найден.");
    }
}