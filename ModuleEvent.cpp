#include "ModuleEvent.h"
#include <string>

ModuleEvent::ModuleEvent(EventType type, int moduleID, int damage, int timeStamp) : type_(type), moduleID_(moduleID), damage_(damage), timeStamp_(timeStamp) {

}
EventType ModuleEvent::getType() const {
	return type_;
}
int ModuleEvent::getModuleID() const {
	return moduleID_;
}
int ModuleEvent::getDamage() const {
	return damage_;
}
int ModuleEvent::getTimeStamp() const {
	return timeStamp_;
}