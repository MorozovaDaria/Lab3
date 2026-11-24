#include "MoveHandler.h"
#include "StationFacade.h"
#include "MoveModuleCommand.h"
#include <sstream>

MoveHandler::MoveHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool MoveHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;
    int fromIndex, toIndex;

    if (iss >> action >> fromIndex >> toIndex && action == "move") {
        auto command = std::make_shared<MoveModuleCommand>(facade_->getMediator(), fromIndex, toIndex);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}