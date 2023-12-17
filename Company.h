#pragma once
#include "LinkedList.h"
#include "LeaveEvent.h"
#include "ArrivalEvent.h"
#include "Station.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include "UI.h"
using namespace std;

class Company {
private:
    LinkedList<Station*> stations;
    Queue<Event*> events;
    Queue<Passenger*> finishedPassengers;
    UI ui;
   
    int promotedPassengers;

    int numberOfStations;

    int timeBetweenStations;

    int numberOfWBus;

    int numberOfMBus;

    int capacityWBus;

    int capacityMBus;

    int tripsBeforeCheckup;

    int checkupDurationWBus;

    int checkupDurationMBus;

    int maxWaitingTime;

    int getOnOffTime;

    int numberOfEvents;

    Event* createArrivalEvent(ifstream& inputFile);
    Event* createLeaveEvent(ifstream& inputFile);
    void randomAssigning(int timestep);
    bool isAllListsEmpty();
    void generateOutputFile();
    string timestepToHHMM(int timestep);

public:
    Company();
    void readInputFile(string inputFileName);
    void startSimulation();
};
