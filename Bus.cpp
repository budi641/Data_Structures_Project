#include "Bus.h"

Bus::Bus(bool isMixed, int capacity, int maintenanceTime)
    : isMixed(isMixed), capacity(capacity), maintenanceTime(maintenanceTime) {
}

bool Bus::getIsMixed() const {
    return isMixed;
}

int Bus::getCapacity() const {
    return capacity;
}

int Bus::getMaintenanceTime() const {
    return maintenanceTime;
}

void Bus::addPassenger(Passenger* passenger) {
    passengers.InsertEnd(passenger);
}

Passenger* Bus::removePassenger(int currentStation) {
    return passengers.IsEmpty() && passengers[0]->getEndStation() == currentStation ? nullptr : passengers.RemoveAt(0);
}
