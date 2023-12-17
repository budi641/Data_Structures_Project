#pragma once
#include "Event.h"
#include "LinkedList.h"

class LeaveEvent : public Event 
{
    int start;
public:
    LeaveEvent(int timeStamp, int id,int start);

    void execute(LinkedList<Station*> stations);
};
