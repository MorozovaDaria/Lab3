#include "ExitHandler.h"
#include "StationFacade.h"
#include <iostream>
#include <cstdlib>

ExitHandler::ExitHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool ExitHandler::handle(const std::string& cmd) {
    if (cmd == "exit") {
        std::cout << "Завершение работы программы..." << std::endl;
        std::exit(0);
    }

    return next_ ? next_->handle(cmd) : false;
}