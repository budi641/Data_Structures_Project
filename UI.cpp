#include "UI.h"
using namespace std;

UI::UI()  
{
    
}


void UI::processInput()
{
    ifstream inputFile(inputFileName);
 
    inputFile >> numberOfStations >> timeBetweenStations;

    inputFile >> numberOfWBus >> numberOfMBus;

    inputFile >> capacityWBus >> capacityMBus;

    inputFile >> tripsBeforeCheckup >> checkupDurationWBus >> checkupDurationMBus;

    inputFile >> maxWaitingTime >> getOnOffTime;

    inputFile >> numberOfEvents;

    Events = new ArrayQueue<Event*>(numberOfEvents);


  /* cout << numberOfStations << " " << timeBetweenStations << endl;

    cout << numberOfWBus << " " << numberOfMBus << endl;

    cout << capacityWBus << " " << capacityMBus << endl;

    cout << tripsBeforeCheckup << " " << checkupDurationWBus << " " << checkupDurationMBus << endl;

    cout << maxWaitingTime << " " << getOnOffTime << endl;

    cout << numberOfEvents << endl;*/
    
    
    string line;
    getline(inputFile, line);
    for (int i = 0; i < numberOfEvents; ++i) 
    {
        getline(inputFile, line);

        processEvent(line);
    }

  
    inputFile.close();
}

void UI::processEvent(const string& line)
{
    stringstream ss(line);
    string eventType;
    ss >> eventType;

    if (eventType == "A") 
    {
        
        string passengerType, eventTime, id, start, end, sptype;
        ss >> passengerType >> eventTime >> id >> start >> end >> sptype;
       cout << "A " << passengerType<<" "<<eventTime<<" "<<id<<" "<<start<<" "<<end<<" "<< sptype << endl;
        int ID = stoi(id);

        int START = stoi(start);

        int END = stoi(end);

        int h = stoi(eventTime.substr(0,2));

        int m = stoi(eventTime.substr(2, 2));

        SimulationTime tempTime(h, m, 0);

        Station tempStartStation(START);

        Station tempEndStation(END);

        PassengerType tempPassngerType;

        if (passengerType == "NP")
        {
            tempPassngerType = Normal;
        }
        else if (passengerType == "SP")
        {

            tempPassngerType = SpecialCase;
        }
        else if (passengerType == "WP")
        {
            tempPassngerType = WheelChair;

        }
        
        Passenger tempPassenger(ID,tempPassngerType,tempStartStation,tempEndStation);
        
        ArrivalEvent tempEvent(tempTime, tempPassenger);

        Event* ptr = &tempEvent;

        Events->enqueue(ptr);
       
        
    }
    else if (eventType == "L") 
    {
        string eventTime, start, id;
        ss >> eventTime >> start >> id;
        cout << "L " << eventTime << " " << id << " " << start << " " << endl;
        int h = stoi(eventTime.substr(0, 2));

        int m = stoi(eventTime.substr(2, 2));

        SimulationTime tempTime(h, m, 0);
    }
}

void UI::setInputFileName(string name)
{
    inputFileName = name;
}



void UI::printOutput()
{
    // Implement output logic here
    
}

int UI::getNumberOfStations() const 
{
    return numberOfStations;
}

int UI::getTimeBetweenStations() const
{
    return timeBetweenStations;
}

int UI::getNumberOfWBus() const 
{
    return numberOfWBus;
}

int UI::getNumberOfMBus() const 
{
    return numberOfMBus;
}

int UI::getCapacityWBus() const 
{
    return capacityWBus;
}

int UI::getCapacityMBus() const 
{
    return capacityMBus;
}

int UI::getTripsBeforeCheckup() const 
{
    return tripsBeforeCheckup;
}

int UI::getCheckupDurationWBus() const 
{
    return checkupDurationWBus;
}

int UI::getCheckupDurationMBus() const 
{
    return checkupDurationMBus;
}

int UI::getMaxWaitingTime() const 
{
    return maxWaitingTime;
}

int UI::getGetOnOffTime() const
{
    return getOnOffTime;
}



int UI::getNumberOfEvents() const 
{
    return numberOfEvents;
}

