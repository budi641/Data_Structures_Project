#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(int timestep, int id) : Event(timestep, id)
{

}

void LeaveEvent::execute(LinkedList<Station*> stations) 
{
    for (auto station : stations) 
    {
        station->passengerLeave(getEventId());
    }
}
