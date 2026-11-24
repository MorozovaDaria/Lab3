#pragma once
#include <memory>

class StationMediator;

class Command {
protected:
    std::shared_ptr<StationMediator> mediator_;

public:
    Command(std::shared_ptr<StationMediator> mediator);
    virtual ~Command() = default;
    virtual void execute() = 0;
};