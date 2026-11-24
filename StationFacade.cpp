#include "StationFacade.h"
#include "StationMediator.h"
#include "Command.h"
#include "CommandHistory.h"
#include "Handler.h"
#include "LoggingProxy.h"
#include <iostream>

StationFacade::StationFacade(std::shared_ptr<StationMediator> mediator) : mediator_(mediator), history_(std::make_shared<CommandHistory>()), handlerChain_(nullptr) {

}

std::shared_ptr<StationMediator> StationFacade::getMediator() const {
    return mediator_;
}

void StationFacade::setHandlerChain(std::shared_ptr<Handler> chain) {
    handlerChain_ = chain;
}

void StationFacade::executeCommand(std::shared_ptr<Command> cmd) {
    if (cmd) {
        cmd->execute();
        history_->push(cmd);
    }
}

void StationFacade::processInput(const std::string& input) {
    if (input.empty()) return;

    if (handlerChain_) {
        bool handled = handlerChain_->handle(input);
        if (!handled) {
            LoggingProxy::log("Facade", "Неизвестная команда: '" + input + "'. Введите 'help' для справки.");
        }
    }
}

std::shared_ptr<CommandHistory> StationFacade::getHistory() const {
    return history_;
}