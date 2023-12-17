#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(int timeStamp, int id,int start) : Event(timeStamp, id),start(start)
{

}

void LeaveEvent::execute(LinkedList<Station*> stations) 
{
    stations[start]->passengerLeave(getEventId());
}
