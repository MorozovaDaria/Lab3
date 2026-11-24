#pragma once
#include <vector>
#include <memory>
#include "Command.h"

class CommandHistory {
private:
    std::vector<std::shared_ptr<Command>> history_;

public:
    CommandHistory() = default;
    ~CommandHistory() = default;

    void push(std::shared_ptr<Command> cmd);
    void undo();
    std::shared_ptr<Command> getLastCommand() const;
};