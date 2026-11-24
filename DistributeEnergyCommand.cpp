#include "DistributeEnergyCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "LoggingProxy.h"

DistributeEnergyCommand::DistributeEnergyCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex, int percent)
    : Command(mediator), moduleIndex_(moduleIndex), percent_(percent) {
}

void DistributeEnergyCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    Module* module = center->getModuleByIndex(moduleIndex_);
    if (!module) {
        LoggingProxy::log("Command", "Ошибка: модуль не найден.");
        return;
    }

    if (percent_ <= 0 || percent_ > 100) {
        LoggingProxy::log("Command", "Ошибка: неверный процент энергии (должен быть от 1 до 100).");
        return;
    }

    double totalEnergy = center->getEnergy();
    double amountToDistribute = totalEnergy * (percent_ / 100.0);

    if (module->requestEnergy(amountToDistribute)) {
        LoggingProxy::log("Command", "Запрошено " + std::to_string(percent_) + "% энергии для модуля [" + module->getName() + "].");
    }
}