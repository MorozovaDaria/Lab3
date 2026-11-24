#pragma once
#include <memory>
#include <string>

class StationMediator;
class Command;
class CommandHistory;
class Handler;

class StationFacade {
private:
    std::shared_ptr<StationMediator> mediator_;
    std::shared_ptr<CommandHistory> history_;
    std::shared_ptr<Handler> handlerChain_;

public:
    StationFacade(std::shared_ptr<StationMediator> mediator);
    ~StationFacade() = default;

    std::shared_ptr<StationMediator> getMediator() const;
    void setHandlerChain(std::shared_ptr<Handler> chain);
    void executeCommand(std::shared_ptr<Command> cmd);
    void processInput(const std::string& input);
    std::shared_ptr<CommandHistory> getHistory() const;
};