#pragma once
#include "Handler.h"

class EnergyHandler : public Handler {
public:
    EnergyHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};