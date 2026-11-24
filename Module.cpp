#include <stdexcept>
#include <string>
#include <algorithm>
#include <iostream>
#include "Module.h"
#include "Station.h"
#include "Damage.h"
#include "ModuleEvent.h"
#include "Types.h"
#include "StationMediator.h"

int Module::nextId_ = 1;

Module::Module(std::string name, int effectiveness, int endurance, int energy, int capacity)
	: name_(name), effectiveness_(effectiveness), durability_(endurance),
	energyConsumption_(energy), capacity_(capacity), isBlocked_(false),
	position_(0), isActive_(false), mediator_(nullptr)
{
	ID_ = nextId_++;
	condition_ = "выключен";
	if (effectiveness > 100 || effectiveness < 0) {
		throw std::invalid_argument("Error");
	}
}

int Module::getID() const {
	return ID_;
}

std::string Module::getName() const {
	return name_;
}

int Module::getEffectiveness() const {
	return effectiveness_;
}

std::string Module::getCondition() const {
	return condition_;
}

Durability& Module::getDurability() {
	return durability_;
}

EnergyConsumption& Module::getEnergyConsumption() {
	return energyConsumption_;
}

Capacity& Module::getCapacity() {
	return capacity_;
}

void Module::activate() {
	condition_ = "включен";
	isActive_ = true;
	notifyActivated();          
}

void Module::deactivate() {
	condition_ = "выключен";
	isActive_ = false;
	notifyActivated();          
}

void Module::setState(const std::string& newState) {
	if (newState == "включен" || newState == "выключен" || newState == "авария" || newState == "ремонт") {
		condition_ = newState;
		isActive_ = (newState == "включен");
	}
	else {
		throw std::invalid_argument("Error");
	}
}

void Module::setEffectiveness(int newEff) {
	if (newEff > 100 || newEff < 0) {
		throw std::invalid_argument("Error");
	}
	effectiveness_ = newEff;
}

void Module::moveToIndex(Station& station, size_t currentIndex, size_t newIndex) {
	station.moveModule(currentIndex, newIndex);
}

void Module::subscribe(IObserver* observer) {
	if (observer != nullptr) {
		observers_.push_back(observer);
	}
}

void Module::unsubscribe(IObserver* observer) {
	observers_.erase(
		std::remove(observers_.begin(), observers_.end(), observer),
		observers_.end()
	);
}

void Module::notify(const ModuleEvent& event) {
	for (IObserver* observer : observers_) {
		if (observer != nullptr) {
			observer->onModuleEvent(event);
		}
	}
}

Module& operator-(Module& module, const Damage& damage) {
	if (module.getIsBlocked()) {
		return module;
	}
	int amount = static_cast<int>(damage.getAmount());
	module.durability_.decrease(amount);

	module.notify(ModuleEvent(EventType::Damaged, module.getID(), amount, 0));
	module.notifyDamaged();     

	if (module.durability_.getValue() <= 0) {
		module.notify(ModuleEvent(EventType::Destroyed, module.getID(), amount, 0));
	}
	return module;
}

Module& operator*(Module& module, double modifier) {
	if (module.getIsBlocked()) {
		return module;
	}
	int newEffectiveness = static_cast<int>(module.effectiveness_ * modifier);
	if (newEffectiveness > 100) newEffectiveness = 100;
	if (newEffectiveness < 0) newEffectiveness = 0;

	module.effectiveness_ = newEffectiveness;
	return module;
}

void Module::getStatus() const {
	std::cout << "Модуль [" << ID_ << "] " << name_
		<< " | Позиция: " << position_
		<< " | Активен: " << (isActive_ ? "Да" : "Нет")
		<< " | Прочность: " << durability_.getValue()
		<< " | Потребление энергии: " << energyConsumption_.getValue() << std::endl;
}

void Module::setMediator(std::shared_ptr<StationMediator> mediator) {
	mediator_ = mediator;
}

void Module::setPosition(int pos) {
	position_ = pos;
}

int Module::getPosition() const {
	return position_;
}

bool Module::getIsActive() const {
	return isActive_;
}

bool Module::requestEnergy(double amount) {
	if (!mediator_) return false;
	return mediator_->requestEnergy(position_, amount);
}

void Module::notifyActivated() {
	if (mediator_) {
		mediator_->notifyActivation(position_);
	}
}

void Module::notifyDamaged() {
	if (mediator_) {
		mediator_->notifyDamage(position_);
	}
}