#pragma once
#include "SimulationTime.h"
#include "Station.h"


enum PassengerType { Normal, SpecialCase, WheelChair };

class Passenger {
public:
    Passenger(int ID, PassengerType type, Station startStation, Station endStation);
    int getID() const;
    PassengerType getType() const;
    Station getStartStation() const;
    Station getDistnationStation() const;
    void setGetOnTime(SimulationTime time);
    void setGetOffTime(SimulationTime time);
    SimulationTime getGetOnTime() const;
    SimulationTime getGetOffTime() const;

private:
    int ID;
    PassengerType type;
    Station startStation;
    Station distStation;
    SimulationTime getOnTime;
    SimulationTime getOffTime;
};




