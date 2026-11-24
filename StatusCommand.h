#pragma once
#include "Command.h"

class StatusCommand : public Command {
private:
    int moduleIndex_;

public:
    StatusCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex = -1);
    void execute() override;
};