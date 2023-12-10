#include "Bus.h"

Bus::Bus(int id, PassengerType type, int capacity, int checkupDuration)
    : id(id), type(type), capacity(capacity), checkupDuration(checkupDuration), remainingCheckupTime(0) {}

int Bus::getId() const {
    return id;
}

PassengerType Bus::getType() const {
    return type;
}

int Bus::getCapacity() const {
    return capacity;
}

int Bus::getCheckupDuration() const {
    return checkupDuration;
}

Station Bus::getCurrentStation() const {
    return currentStation;
}

int Bus::getRemainingCheckupTime() const {
    return remainingCheckupTime;
}

void Bus::moveToStation(Station station) {
    currentStation = station;
}

void Bus::startCheckup() {
    remainingCheckupTime = checkupDuration;
}

void Bus::finishCheckup() {
    remainingCheckupTime = 0;
}
