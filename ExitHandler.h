#pragma once
#include "Handler.h"

class ExitHandler : public Handler {
public:
    ExitHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};