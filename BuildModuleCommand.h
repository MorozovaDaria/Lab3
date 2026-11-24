#pragma once
#include "Command.h"
#include <string>

class BuildModuleCommand : public Command {
private:
    std::string type_;
    std::string name_;

public:
    BuildModuleCommand(std::shared_ptr<StationMediator> mediator, const std::string& type, const std::string& name);
    void execute() override;
};