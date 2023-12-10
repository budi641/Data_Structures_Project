#pragma once
#include "Event.h"
#include "Passenger.h"
#include "Station.h"

class ArrivalEvent : public Event 
{
public:
    ArrivalEvent(SimulationTime time, Passenger passenger);
    void execute() override;

private:
    Passenger passenger;
   
  
};



