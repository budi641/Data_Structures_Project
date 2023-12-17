#pragma once
#include "Event.h"
#include <string>
using namespace std;

class ArrivalEvent : public Event 
{

private:
    string passengerType;
    int startStation;
    int endStation;
    int priority;

public:
    ArrivalEvent(int timestep, int id, string passengerType, int startStation, int endStation, int priority = -1);

    void execute(LinkedList<Station*> stations);
};
