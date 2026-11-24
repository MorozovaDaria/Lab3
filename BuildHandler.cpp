#include "BuildHandler.h"
#include "StationFacade.h"
#include "BuildModuleCommand.h"
#include <sstream>
#include <iostream>

BuildHandler::BuildHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool BuildHandler::handle(const std::string& cmd) {
    std::istringstream iss(cmd);
    std::string action, type, name;

    if (iss >> action >> type && action == "build") {
        std::getline(iss, name);

        size_t firstQuote = name.find('"');
        size_t lastQuote = name.rfind('"');

        if (firstQuote != std::string::npos && lastQuote != std::string::npos && firstQuote < lastQuote) {
            name = name.substr(firstQuote + 1, lastQuote - firstQuote - 1);
        }
        else {
            name = "Безымянный модуль";
        }

        auto command = std::make_shared<BuildModuleCommand>(facade_->getMediator(), type, name);
        facade_->executeCommand(command);
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}