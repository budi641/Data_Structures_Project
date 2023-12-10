#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(SimulationTime time, Passenger passenger, Station startStation)
    : Event(time), passenger(passenger), startStation(startStation) {}

void LeaveEvent::execute() 
{
    // Implementation for handling leave event
}
