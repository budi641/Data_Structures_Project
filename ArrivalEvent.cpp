#include "ArrivalEvent.h"
#include "Passenger.h"

ArrivalEvent::ArrivalEvent(int timestep, int id, string passengerType, int startStation, int endStation, int priority)
    : Event(timestep, id), passengerType(passengerType), startStation(startStation), endStation(endStation), priority(priority) 
{

}

void ArrivalEvent::execute(LinkedList<Station*> stations) 
{
    Passenger* passenger = new Passenger(passengerType, getEventId(), getTimeStep(), startStation, endStation, priority);

    stations[startStation]->addPassenger(passenger);
}
