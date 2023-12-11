#pragma once
#include "Event.h"


class LeaveEvent : public Event 
{
public:
    LeaveEvent(SimulationTime time,int id,int station);

    void execute(Station* st) override;

private:
   
    int Start;

    int ID;



};
