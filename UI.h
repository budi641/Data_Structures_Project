
#include <iostream>
#include <fstream>
#include <sstream>
#include "ArrayQueue.h"
#include "Event.h"
#include "ArrivalEvent.h"
#include "LeaveEvent.h"
#include "Passenger.h"
#include "Station.h"
#include "SimulationTime.h"
using namespace std;

class UI 
{
public:

    UI();

    ArrayQueue<Event*>* Events;

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

