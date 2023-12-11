#pragma once
#include "Event.h"
#include "Station.h"
#include <iostream>
using namespace std;

class ArrivalEvent : public Event 
{
public:
    ArrivalEvent(SimulationTime time,int id,int start,int end,string type,string SPtype);
    void execute(Station* st) override;

private:
    
    int ID;

    int Start;

    int End;

    string Type;

    string SPType;

  
};



