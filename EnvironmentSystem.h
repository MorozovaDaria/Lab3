#pragma once
#include <string>
#include <memory>
#include "Environment.h"

class EnvironmentSystem {
private:
    std::string type_;
    int hazardLevel_;
    std::shared_ptr<Environment> currentEnvironment_;

public:
    EnvironmentSystem(std::shared_ptr<Environment> initialEnv = nullptr);
    ~EnvironmentSystem() = default;

    void changeEnvironment(const std::string& newType, int newHazardLevel);
    void applyEffects();

    std::string getType() const;
    int getHazardLevel() const;
    void setHazardLevel(int level);
    std::shared_ptr<Environment> getCurrentEnvironment() const;
    void setCurrentEnvironment(std::shared_ptr<Environment> env);
};