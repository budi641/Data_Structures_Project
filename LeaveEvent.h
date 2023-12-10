#pragma once
#include "Event.h"
#include "Passenger.h"
#include "Station.h"

class LeaveEvent : public Event {
public:
    LeaveEvent(SimulationTime time, Passenger passenger, Station startStation);
    void execute() override;

private:
    Passenger passenger;
    Station startStation;
};
