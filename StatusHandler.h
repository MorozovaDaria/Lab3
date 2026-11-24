#pragma once
#include "Handler.h"

class StatusHandler : public Handler {
public:
    StatusHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};