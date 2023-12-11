#pragma once
#include "Passenger.h"
#include "Station.h"

class Event 
{
public:
    Event();
    Event(SimulationTime time);
    SimulationTime getTime() const;
    void setTime(SimulationTime t);
    virtual void execute(Station* st) = 0;

private:

    SimulationTime Time;
};




