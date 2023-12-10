#include "ArrivalEvent.h"

ArrivalEvent::ArrivalEvent(SimulationTime time, Passenger passenger)
    : Event(time), passenger(passenger){}

void ArrivalEvent::execute() 
{
    
}
