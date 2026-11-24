#pragma once
#include "Command.h"

class DistributeEnergyCommand : public Command {
private:
    int moduleIndex_;
    int percent_;

public:
    DistributeEnergyCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex, int percent);
    void execute() override;
};