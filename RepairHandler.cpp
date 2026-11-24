#include "RepairHandler.h"
#include "StationFacade.h"
#include "RepairModuleCommand.h"
#include <sstream>

RepairHandler::RepairHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool RepairHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;
    int index;

    if (iss >> action >> index && action == "repair") {
        auto command = std::make_shared<RepairModuleCommand>(facade_->getMediator(), index);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}