#include "DeactivateHandler.h"
#include "StationFacade.h"
#include "DeactivateModuleCommand.h"
#include <sstream>

DeactivateHandler::DeactivateHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool DeactivateHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;
    int index;

    if (iss >> action >> index && action == "deactivate") {
        auto command = std::make_shared<DeactivateModuleCommand>(facade_->getMediator(), index);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}
