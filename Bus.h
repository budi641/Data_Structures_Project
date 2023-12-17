#pragma once
#include "LinkedList.h"
#include "Passenger.h"

class Bus {
private:
    bool isMixed;
    int capacity;
    int maintenanceTime;
    LinkedList<Passenger*> passengers;

public:
    Bus(bool isMixed, int capacity, int maintenanceTime);

    bool getIsMixed() const;
    int getCapacity() const;
    int getMaintenanceTime() const;

    void addPassenger(Passenger* passenger);
    Passenger* removePassenger(int currentStation);
};
