#pragma once
#include "Handler.h"

class RepairHandler : public Handler {
public:
    RepairHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};