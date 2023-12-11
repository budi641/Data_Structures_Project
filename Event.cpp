#include "Event.h"

Event::Event()
{
}

Event::Event(SimulationTime time) : Time(time) {}

SimulationTime Event::getTime() const {
    return Time;
}

void Event::setTime(SimulationTime t)
{
    Time = t;
}
