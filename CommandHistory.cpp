#include "CommandHistory.h"
#include "LoggingProxy.h"

void CommandHistory::push(std::shared_ptr<Command> cmd) {
    if (cmd) {
        history_.push_back(cmd);
    }
}

void CommandHistory::undo() {
    if (!history_.empty()) {
        history_.pop_back();
        LoggingProxy::log("History", "Последняя команда отменена.");
    }
    else {
        LoggingProxy::log("History", "История пуста, нечего отменять.");
    }
}

std::shared_ptr<Command> CommandHistory::getLastCommand() const {
    if (!history_.empty()) {
        return history_.back();
    }
    return nullptr;
}