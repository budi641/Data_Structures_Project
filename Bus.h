#pragma once
#include "Passenger.h"
#include "Station.h"

class Bus 
{
public:
    Bus(int id, PassengerType type, int capacity, int checkupDuration);

    int getId() const;
    PassengerType getType() const;
    int getCapacity() const;
    int getCheckupDuration() const;
    Station getCurrentStation() const;
    int getRemainingCheckupTime() const;

    void moveToStation(Station station);
    void startCheckup();
    void finishCheckup();

private:
    int id;
    PassengerType type;
    int capacity;
    int checkupDuration;
    Station currentStation;
    int remainingCheckupTime;
};



