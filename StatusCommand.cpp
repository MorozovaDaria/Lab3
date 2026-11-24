#include "StatusCommand.h"
#include "StationMediator.h"
#include "CommandCenter.h"
#include "Module.h"
#include "EnergySystem.h"
#include "EnvironmentSystem.h"
#include <iostream>

StatusCommand::StatusCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex) : Command(mediator), moduleIndex_(moduleIndex) {

}

void StatusCommand::execute() {
    if (!mediator_) return;

    auto center = mediator_->getCommandCenter();
    if (!center) return;

    if (moduleIndex_ >= 0) {
        Module* module = center->getModuleByIndex(moduleIndex_);
        if (module) {
            module->getStatus();
        }
        else {
            std::cout << "Ошибка: модуль с индексом " << moduleIndex_ << " не найден." << std::endl;
        }
        return;
    }

    std::cout << "\nСТАТУС СТАНЦИИ" << std::endl;
    std::cout << "Энергия: " << center->getEnergy() << std::endl;
    std::cout << "Кислород: " << center->getOxygen() << "%" << std::endl;
    std::cout << "Безопасность: " << center->getSafetyLevel() << std::endl;

    auto envSys = mediator_->getEnvironmentSystem();
    if (envSys) {
        std::cout << "Среда: " << envSys->getType() << " (Опасность: " << envSys->getHazardLevel() << ")" << std::endl;
    }

    std::cout << "Модули (" << center->size() << "/" << center->maxSize() << "):" << std::endl;
    for (size_t i = 0; i < center->size(); ++i) {
        Module* mod = center->getModuleByIndex(i);
        if (mod) {
            std::cout << "  ";
            mod->getStatus();
        }
    }
    std::cout << "\n" << std::endl;
}