#pragma once
#include "Station.h"
#include <iostream>
using namespace std;

class UI 
{
private:
    bool isSilent;

public:
    UI();

    void getMode();
    void printSimulationInfo(int timeStamp, LinkedList<Station*>& stations, Queue<Passenger*>& finishedPassengers);
    void displayEndMessage();
};

