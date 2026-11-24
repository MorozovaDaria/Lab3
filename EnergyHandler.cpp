#include "EnergyHandler.h"
#include "StationFacade.h"
#include "DistributeEnergyCommand.h"
#include <sstream>
#include <iostream>

EnergyHandler::EnergyHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool EnergyHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;
    int index, percent;

    if (iss >> action >> index >> percent && action == "energy") {
        if (percent < 1 || percent > 100) {
            std::cout << "Ошибка: процент энергии должен быть от 1 до 100." << std::endl;
            return true;
        }
        auto command = std::make_shared<DistributeEnergyCommand>(facade_->getMediator(), index, percent);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}