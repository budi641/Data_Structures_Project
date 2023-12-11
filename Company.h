#pragma once
#include"SimulationTime.h"
#include"Passenger.h"
#include"Bus.h"
#include"Station.h"
#include"Event.h"
#include"LeaveEvent.h"
#include"ArrivalEvent.h"
#include"UI.h"
#include<iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "ArrayQueue.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

class Company
{
public:

        Company();

        void runSimulation();

        void processInput();

        void processEvent(const string& line);

        void setInputFileName(string name);

        void printOutput();

        int getNumberOfStations() const;

        int getTimeBetweenStations() const;

        int getNumberOfWBus() const;

        int getNumberOfMBus() const;

        int getCapacityWBus() const;

        int getCapacityMBus() const;

        int getTripsBeforeCheckup() const;

        int getCheckupDurationWBus() const;

        int getCheckupDurationMBus() const;

        int getMaxWaitingTime() const;

        int getGetOnOffTime() const;

        int getNumberOfEvents() const;


private:

    bool Run;

    SimulationTime GlobalTime;

    UI IO_Manager;

    Station* stations;

    ArrayQueue<Event*>* Events;

    string inputFileName;

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
};


