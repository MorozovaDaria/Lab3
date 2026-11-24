#pragma once
#include "Command.h"

class MoveModuleCommand : public Command {
private:
    int fromIndex_;
    int toIndex_;

public:
    MoveModuleCommand(std::shared_ptr<StationMediator> mediator, int fromIndex, int toIndex);
    void execute() override;
};