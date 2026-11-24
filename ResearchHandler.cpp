#include "ResearchHandler.h"
#include "StationFacade.h"
#include "StartResearchCommand.h"
#include <sstream>

ResearchHandler::ResearchHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool ResearchHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action;
    int index;

    if (iss >> action >> index && action == "research") {
        auto command = std::make_shared<StartResearchCommand>(facade_->getMediator(), index);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}