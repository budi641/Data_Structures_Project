#include "ArrivalEvent.h"



ArrivalEvent::ArrivalEvent(SimulationTime time, int id, int start, int end, string type, string SPtype)
{
    setTime(time);

    ID = id;

    Start = start;

    End = end;

    Type = type;

    SPType = SPtype;

}

void ArrivalEvent::execute(Station* st)
{
    Station EventStation = st[Start-1];



   // Passenger EventPassenger = new Passenger();
    
}
