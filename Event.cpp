#include "Event.h"

Event::Event(int timeStep, int eventId)
{
    this->timeStep = timeStep;
    this->eventId = eventId;
}

void Event::execute(LinkedList<Station*> stations)
{
    
}



int Event::getEventId() const
{
    return eventId;
}

int Event::getTimeStep() const
{
    return timeStep;
}
