#include "MoveModuleCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "LoggingProxy.h"

MoveModuleCommand::MoveModuleCommand(std::shared_ptr<StationMediator> mediator, int fromIndex, int toIndex)
    : Command(mediator), fromIndex_(fromIndex), toIndex_(toIndex) {
}

void MoveModuleCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    Module* module = center->getModuleByIndex(fromIndex_);
    if (!module) {
        LoggingProxy::log("Command", "Ошибка: модуль с индексом " + std::to_string(fromIndex_) + " не найден.");
        return;
    }

    if (toIndex_ < 0 || toIndex_ >= static_cast<int>(center->size())) {
        LoggingProxy::log("Command", "Ошибка: неверный целевой индекс.");
        return;
    }

    std::string name = module->getName();
    center->moveModule(fromIndex_, toIndex_);
    LoggingProxy::log("Command", "Модуль [" + name + "] перемещён с позиции " +
        std::to_string(fromIndex_) + " на " + std::to_string(toIndex_));
}