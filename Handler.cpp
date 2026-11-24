#include "Handler.h"

Handler::Handler(std::shared_ptr<StationFacade> facade) : facade_(facade), next_(nullptr) {

    }

void Handler::setNext(std::shared_ptr<Handler> next) {
    next_ = next;
}