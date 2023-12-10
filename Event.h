#pragma once
#include "Passenger.h"
#include "Station.h"

class Event 
{
public:
    Event(SimulationTime time);
    SimulationTime getTime() const;
    virtual void execute() = 0;

private:

    SimulationTime time;
};




