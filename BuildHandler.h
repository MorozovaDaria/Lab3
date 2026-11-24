#pragma once
#include "Handler.h"

class BuildHandler : public Handler {
public:
    BuildHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};