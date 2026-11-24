#pragma once
#include "Handler.h"

class ActivateHandler : public Handler {
public:
    ActivateHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};
