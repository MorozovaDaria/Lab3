#include "EnvironmentSystem.h"
#include "LoggingProxy.h"

EnvironmentSystem::EnvironmentSystem(std::shared_ptr<Environment> initialEnv) : type_("EarthOrbit"), hazardLevel_(10), currentEnvironment_(initialEnv) {

}

void EnvironmentSystem::changeEnvironment(const std::string& newType, int newHazardLevel) {
    type_ = newType;
    hazardLevel_ = newHazardLevel;

    if (hazardLevel_ < 0) hazardLevel_ = 0;
    if (hazardLevel_ > 100) hazardLevel_ = 100;

    LoggingProxy::log("Environment", "Среда изменена на: " + type_ + " | Уровень опасности: " + std::to_string(hazardLevel_));
}

void EnvironmentSystem::applyEffects() {
    if (type_ == "EarthOrbit") {
        LoggingProxy::log("Environment", "Орбита Земли: умеренный риск. Незначительное влияние на станцию.");
    }
    else if (type_ == "DeepSpace") {
        LoggingProxy::log("Environment", "Глубокий космос: повышенный расход энергии (x1.5), радиация. Периодические повреждения!");
    }
    else if (type_ == "AsteroidField") {
        LoggingProxy::log("Environment", "Астероидное поле: ВЫСОКИЙ РИСК! Снижение прочности модулей, исследовательские модули блокируются!");
    }
    else {
        LoggingProxy::log("Environment", "Неизвестная среда: " + type_ + " | Опасность: " + std::to_string(hazardLevel_));
    }
}

std::string EnvironmentSystem::getType() const {
    return type_;
}

int EnvironmentSystem::getHazardLevel() const {
    return hazardLevel_;
}

void EnvironmentSystem::setHazardLevel(int level) {
    hazardLevel_ = level;
    if (hazardLevel_ < 0) hazardLevel_ = 0;
    if (hazardLevel_ > 100) hazardLevel_ = 100;
}

std::shared_ptr<Environment> EnvironmentSystem::getCurrentEnvironment() const {
    return currentEnvironment_;
}

void EnvironmentSystem::setCurrentEnvironment(std::shared_ptr<Environment> env) {
    currentEnvironment_ = env;
}