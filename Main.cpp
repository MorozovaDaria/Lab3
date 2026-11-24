#include <iostream>
#include <memory>
#include <string>

#include "CommandCenter.h"
#include "EnergySystem.h"
#include "EnvironmentSystem.h"
#include "StationMediator.h"
#include "StationFacade.h"
#include "StandardModuleFactory.h"
#include "AdvancedModuleFactory.h"

#include "ActivateHandler.h"
#include "DeactivateHandler.h"
#include "MoveHandler.h"
#include "RepairHandler.h"
#include "EnergyHandler.h"
#include "ResearchHandler.h"
#include "BuildHandler.h"
#include "StatusHandler.h"
#include "HelpHandler.h"
#include "ExitHandler.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(LC_ALL, "RU");

    auto center = std::make_shared<CommandCenter>(20);
    auto energySys = std::make_shared<EnergySystem>(1000.0);
    auto envSys = std::make_shared<EnvironmentSystem>();

    auto mediator = std::make_shared<StationMediator>();
    mediator->setCommandCenter(center);
    mediator->setEnergySystem(energySys);
    mediator->setEnvironmentSystem(envSys);

    center->setMediator(mediator);

    auto facade = std::make_shared<StationFacade>(mediator);

    auto helpHandler = std::make_shared<HelpHandler>(facade);
    auto activateHandler = std::make_shared<ActivateHandler>(facade);
    auto deactivateHandler = std::make_shared<DeactivateHandler>(facade);
    auto moveHandler = std::make_shared<MoveHandler>(facade);
    auto repairHandler = std::make_shared<RepairHandler>(facade);
    auto energyHandler = std::make_shared<EnergyHandler>(facade);
    auto researchHandler = std::make_shared<ResearchHandler>(facade);
    auto buildHandler = std::make_shared<BuildHandler>(facade);
    auto statusHandler = std::make_shared<StatusHandler>(facade);
    auto exitHandler = std::make_shared<ExitHandler>(facade);

    activateHandler->setNext(deactivateHandler);
    deactivateHandler->setNext(moveHandler);
    moveHandler->setNext(repairHandler);
    repairHandler->setNext(energyHandler);
    energyHandler->setNext(researchHandler);
    researchHandler->setNext(buildHandler);
    buildHandler->setNext(statusHandler);
    statusHandler->setNext(helpHandler);
    helpHandler->setNext(exitHandler);

    facade->setHandlerChain(activateHandler);

    std::cout << "Добро пожаловать в систему управления станцией!" << std::endl;
    std::cout << "Введите команду (help - справка):" << std::endl;

    std::string input;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        facade->processInput(input);
    }
    return 0;
}