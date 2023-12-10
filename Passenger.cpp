#include "Passenger.h"
#include "Passenger.h"

Passenger::Passenger(int ID, PassengerType type, Station startStation, Station endStation)
    : ID(ID), type(type), startStation(startStation), distStation(endStation), getOnTime(), getOffTime() {}

int Passenger::getID() const 
{
    return ID;
}

PassengerType Passenger::getType() const 
{
    return type;
}

Station Passenger::getStartStation() const 
{
    return startStation;
}

Station Passenger::getDistnationStation() const
{
    return distStation;
}

void Passenger::setGetOnTime(SimulationTime time) 
{
    getOnTime = time;
}

void Passenger::setGetOffTime(SimulationTime time)
{
    getOffTime = time;
}

SimulationTime Passenger::getGetOnTime() const 
{
    return getOnTime;
}

SimulationTime Passenger::getGetOffTime() const
{
    return getOffTime;
}
