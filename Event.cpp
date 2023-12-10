#include "Event.h"

Event::Event(SimulationTime time) : time(time) {}

SimulationTime Event::getTime() const {
    return time;
}
