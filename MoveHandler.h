#pragma once
#include "Handler.h"

class MoveHandler : public Handler {
public:
    MoveHandler(std::shared_ptr<StationFacade> facade);
    bool handle(const std::string& cmd) override;
};
