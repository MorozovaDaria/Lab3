#include "StatusHandler.h"
#include "StationFacade.h"
#include "StatusCommand.h"
#include <sstream>

StatusHandler::StatusHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool StatusHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;

    if (!(iss >> action) || action != "status") {
        return next_ ? next_->handle(cmd) : false;
    }

    int index = -1;
    iss >> index;

    auto command = std::make_shared<StatusCommand>(facade_->getMediator(), index);
    facade_->executeCommand(command);
    return true;
}