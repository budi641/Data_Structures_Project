#pragma once
#include "Event.h"
#include "LinkedList.h"

class LeaveEvent : public Event 
{
public:
    LeaveEvent(int timestep, int id);

    void execute(LinkedList<Station*> stations);
};
