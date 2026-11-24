#pragma once
#include "Handler.h"

class HelpHandler : public Handler {
public:
    HelpHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};