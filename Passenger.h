#pragma once
#include "SimulationTime.h"
#include "Station.h"


enum PassengerType { Normal, SpecialCase,POD,Pregnant,Aged, WheelChair };

class Passenger {
public:
    Passenger(int ID, PassengerType type, Station startStation, Station endStation);
    int getID() const;
    PassengerType getType() const;
    Station getStartStation() const;
    Station getDistnationStation() const;
    void setGetOnTime(int time);
    void setGetOffTime(int time);
    int getGetOnTime() const;
    int getGetOffTime() const;

private:
    int ID;
    PassengerType type;
    Station startStation;
    Station distStation;
    int getOnTime;
    int getOffTime;
};




