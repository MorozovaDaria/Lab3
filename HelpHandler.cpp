#include "HelpHandler.h"
#include "StationFacade.h"
#include <iostream>
#include <string>

HelpHandler::HelpHandler(std::shared_ptr<StationFacade> facade) : Handler(facade) {

}

bool HelpHandler::handle(const std::string& cmd) {
    if (cmd == "help") {
        std::cout << "Доступные команды:" << std::endl;
        std::cout << "  activate <индекс>            - включить модуль" << std::endl;
        std::cout << "  deactivate <индекс>          - выключить модуль" << std::endl;
        std::cout << "  move <индекс> <новый_индекс> - переместить модуль" << std::endl;
        std::cout << "  repair <индекс>              - отремонтировать модуль" << std::endl;
        std::cout << "  energy <индекс> <процент>    - распределить энергию" << std::endl;
        std::cout << "  research <индекс>            - запустить исследование" << std::endl;
        std::cout << "  build <тип> \"имя\"          - построить модуль" << std::endl;
        std::cout << "  status [индекс]              - показать статус" << std::endl;
        std::cout << "  help                         - показать эту справку" << std::endl;
        std::cout << "  exit                         - выход" << std::endl;
        return true;
    }

    return next_ ? next_->handle(cmd) : false;
}