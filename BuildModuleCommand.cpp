#include "BuildModuleCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "ModuleFactory.h"
#include "StandardModuleFactory.h"
#include "AdvancedModuleFactory.h"
#include "LoggingProxy.h"

BuildModuleCommand::BuildModuleCommand(std::shared_ptr<StationMediator> mediator, const std::string& type, const std::string& name) : Command(mediator), type_(type), name_(name) {

}

void BuildModuleCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    if (center->size() >= center->maxSize()) {
        LoggingProxy::log("Command", "Ошибка: на станции нет свободного места для нового модуля.");
        return;
    }

    std::unique_ptr<ModuleFactory> factory;

    if (type_ == "reactor" || type_ == "physics" || type_ == "medical") {
        factory = std::make_unique<AdvancedModuleFactory>();
    }
    else {
        factory = std::make_unique<StandardModuleFactory>();
    }

    auto newModule = factory->createModule(type_, name_);

    if (newModule) {
        center->addModule(std::move(newModule));
        LoggingProxy::log("Command", "Модуль [" + name_ + "] успешно построен и добавлен на станцию.");
    }
    else {
        LoggingProxy::log("Command", "Ошибка: неизвестный тип модуля '" + type_ + "'.");
    }
}