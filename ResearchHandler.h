#pragma once
#include "Handler.h"

class ResearchHandler : public Handler {
public:
    ResearchHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};