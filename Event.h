#pragma once
#include "Station.h"

class Event
{
private:
    int timeStep;
    int eventId;

public:
    Event(int timeStep, int eventId);

    virtual void execute(LinkedList<Station*> stations) = 0;

    int getEventId() const;

    int getTimeStep() const;
};
