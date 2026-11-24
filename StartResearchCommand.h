#pragma once
#include "Command.h"

class StartResearchCommand : public Command {
private:
    int moduleIndex_;

public:
    StartResearchCommand(std::shared_ptr<StationMediator> mediator, int moduleIndex);
    void execute() override;
};