#pragma once
#include "Command.h"

class RepairModuleCommand : public Command {
private:
    int moduleIndex_;

public:
    RepairModuleCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex);
    void execute() override;
};