#include "ActivateHandler.h"
#include "StationFacade.h"
#include "ActivateModuleCommand.h"
#include <sstream>
#include <iostream>

ActivateHandler::ActivateHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool ActivateHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;
    int index;

    if (iss >> action >> index && action == "activate") {
        auto command = std::make_shared<ActivateModuleCommand>(facade_->getMediator(), index);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}