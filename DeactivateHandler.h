#pragma once
#include "Handler.h"

class DeactivateHandler : public Handler {
public:
    DeactivateHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};
