#pragma once
#include <string>
#include <memory>

class StationFacade;

class Handler {
protected:
    std::shared_ptr<Handler> next_;
    std::shared_ptr<StationFacade> facade_;

public:
    Handler(std::shared_ptr<StationFacade> facade);
    virtual ~Handler() = default;

    void setNext(std::shared_ptr<Handler> next);
    virtual bool handle(const std::string& cmd) = 0;
};
