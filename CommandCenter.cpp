#include <stdexcept>
#include <iostream>
#include "CommandCenter.h"
#include "Types.h"
#include "StationMediator.h"

CommandCenter::CommandCenter(size_t maxModules, double energy, double oxygen, int safetyLevel)
    : maxModules_(maxModules), energy_(energy), oxygen_(oxygen), safetyLevel_(safetyLevel) {
    if (maxModules == 0) {
        throw std::invalid_argument("Error");
    }
}

bool CommandCenter::addModule(std::unique_ptr<Module> module) {
    if (modules_.size() >= maxModules_ || !module) {
        return false;
    }
    module->subscribe(this);
    module->setPosition(static_cast<int>(modules_.size()));

    if (mediator_) {
        module->setMediator(mediator_);
    }

    modules_.push_back(std::move(module));
    return true;
}

void CommandCenter::removeModuleById(int id) {
    for (auto it = modules_.begin(); it != modules_.end(); ++it) {
        if ((*it)->getID() == id) {
            (*it)->unsubscribe(this);
            modules_.erase(it);
            
            for (size_t i = 0; i < modules_.size(); ++i) {
                modules_[i]->setPosition(static_cast<int>(i));
            }
            return;
        }
    }
}

Module* CommandCenter::findModuleById(int id) {
    for (auto& module : modules_) {
        if (module->getID() == id) {
            return module.get();
        }
    }
    return nullptr;
}

size_t CommandCenter::size() const {
    return modules_.size();
}

size_t CommandCenter::maxSize() const {
    return maxModules_;
}

double CommandCenter::getEnergy() const {
    return energy_;
}

double CommandCenter::getOxygen() const {
    return oxygen_;
}

int CommandCenter::getSafetyLevel() const {
    return safetyLevel_;
}

void CommandCenter::setEnvironment(std::shared_ptr<Environment> env) {
    currentEnvironment_ = env;
}

std::shared_ptr<Environment> CommandCenter::getEnvironment() const {
    return currentEnvironment_;
}

void CommandCenter::applyCurrentEnvironment() {
    if (!currentEnvironment_) return;
    for (auto& module : modules_) {
        currentEnvironment_->applyEffect(*module);
    }
}

void CommandCenter::onModuleEvent(const ModuleEvent& event) {
    switch (event.getType()) {
    case EventType::Damaged:
        safetyLevel_ -= event.getDamage() / 10;
        if (safetyLevel_ < 0) safetyLevel_ = 0;
        std::cout << "[CommandCenter] Module " << event.getModuleID()
            << " damaged. Safety level: " << safetyLevel_ << std::endl;
        break;
    case EventType::Destroyed:
        std::cout << "[CommandCenter] Module " << event.getModuleID()
            << " destroyed. Removing..." << std::endl;
        removeModuleById(event.getModuleID());
        safetyLevel_ -= 20;
        if (safetyLevel_ < 0) safetyLevel_ = 0;
        break;
    case EventType::Activated:
        std::cout << "[CommandCenter] Module " << event.getModuleID()
            << " activated." << std::endl;
        break;
    case EventType::EnergyConsumed:
        energy_ -= event.getDamage();
        if (energy_ < 0) energy_ = 0;
        break;
    }
}

CommandCenter& operator+(CommandCenter& center, const ResourcePackage& package) {
    center.energy_ += package.getEnergy();
    center.oxygen_ += package.getOxygen();
    center.safetyLevel_ += package.getSafetyLevel();
    if (center.safetyLevel_ > 100) center.safetyLevel_ = 100;
    return center;
}

//Lab 3
void CommandCenter::setMediator(std::shared_ptr<StationMediator> mediator) {
    mediator_ = mediator;
}

Module* CommandCenter::getModuleByIndex(size_t index) {
    if (index >= modules_.size()) {
        return nullptr;
    }
    return modules_[index].get();
}

bool CommandCenter::spendEnergy(double amount) {
    if (energy_ >= amount) {
        energy_ -= amount;
        return true;
    }
    return false;
}

void CommandCenter::restoreEnergy(double amount) {
    energy_ += amount;
}

void CommandCenter::setSafetyLevel(int level) {
    safetyLevel_ = level;
}

void CommandCenter::setOxygen(double amount) {
    oxygen_ = amount;
}

void CommandCenter::swapModules(int fromIndex, int toIndex) {
    if (fromIndex < 0 || toIndex < 0) return;
    if (fromIndex >= static_cast<int>(modules_.size()) || toIndex >= static_cast<int>(modules_.size())) return;

    std::swap(modules_[fromIndex], modules_[toIndex]);

    modules_[fromIndex]->setPosition(fromIndex);
    modules_[toIndex]->setPosition(toIndex);
}

void CommandCenter::moveModule(int fromIndex, int toIndex) {
    if (fromIndex < 0 || toIndex < 0) return;
    if (fromIndex >= static_cast<int>(modules_.size()) || toIndex >= static_cast<int>(modules_.size())) return;
    if (fromIndex == toIndex) return;

    auto module = std::move(modules_[fromIndex]);
    modules_.erase(modules_.begin() + fromIndex);
    modules_.insert(modules_.begin() + toIndex, std::move(module));

    for (size_t i = 0; i < modules_.size(); ++i) {
        modules_[i]->setPosition(static_cast<int>(i));
    }
}