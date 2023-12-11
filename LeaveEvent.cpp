#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(SimulationTime time, int id, int station)
{
    setTime(time);

    ID = id;

    Start = station;

}

void LeaveEvent::execute(Station* st)
{

    Station EventStation = st[Start - 1];

    
}
