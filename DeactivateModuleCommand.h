#pragma once
#include "Command.h"

class DeactivateModuleCommand : public Command {
private:
    int moduleIndex_;

public:
    DeactivateModuleCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex);
    void execute() override;
};