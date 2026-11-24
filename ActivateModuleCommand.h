#pragma once
#include "Command.h"

class ActivateModuleCommand : public Command {
private:
    int moduleIndex_;

public:
    ActivateModuleCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex);
    void execute() override;
};