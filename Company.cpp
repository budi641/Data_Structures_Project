#include "Company.h"
using namespace std;

void Company::processInput()
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

void Company::processEvent(const string& line)
{
    stringstream ss(line);
    string eventType;
    ss >> eventType;

    if (eventType == "A")
    {

        string passengerType, eventTime, id, start, end, sptype;
        ss >> passengerType >> eventTime >> id >> start >> end >> sptype;
        cout << "A " << passengerType << " " << eventTime << " " << id << " " << start << " " << end << " " << sptype << endl;
        int EventID= stoi(id);

        int EventStart = stoi(start);

        int EventEnd = stoi(end);

        int h = stoi(eventTime.substr(0, 2));

        int m = stoi(eventTime.substr(2, 2));

        SimulationTime EventTime(h, m, 0);

        ArrivalEvent tempEvent(EventTime,EventID,EventStart,EventEnd,passengerType,sptype);

        Event* ptr = &tempEvent;

        Events->enqueue(ptr);

    

    }
    else if (eventType == "L")
    {
        string eventTime, start, id;

        ss >> eventTime >> start >> id;

        cout << "L " << eventTime << " " << id << " " << start << " " << endl;
        int EventID = stoi(id);

        int EventStart = stoi(start);

        int h = stoi(eventTime.substr(0, 2));

        int m = stoi(eventTime.substr(2, 2));

        SimulationTime tempTime(h, m, 0);

        LeaveEvent tempEvent(tempTime, EventID, EventStart);

        Event* ptr = &tempEvent;

        Events->enqueue(ptr);
    }
}

Company::Company()
{

    GlobalTime.setTime(4, 0, 0);

    Run = true;

    cout << "please enter the name of the input file:" << endl;

    cin >> inputFileName;

    stations = new Station[numberOfStations];

    processInput();










}

void Company::setInputFileName(string name)
{
    inputFileName = name;
}

void Company::printOutput()
{
    // Implement output logic here

}

int Company::getNumberOfStations() const
{
    return numberOfStations;
}

int Company::getTimeBetweenStations() const
{
    return timeBetweenStations;
}

int Company::getNumberOfWBus() const
{
    return numberOfWBus;
}

int Company::getNumberOfMBus() const
{
    return numberOfMBus;
}

int Company::getCapacityWBus() const
{
    return capacityWBus;
}

int Company::getCapacityMBus() const
{
    return capacityMBus;
}

int Company::getTripsBeforeCheckup() const
{
    return tripsBeforeCheckup;
}

int Company::getCheckupDurationWBus() const
{
    return checkupDurationWBus;
}

int Company::getCheckupDurationMBus() const
{
    return checkupDurationMBus;
}

int Company::getMaxWaitingTime() const
{
    return maxWaitingTime;
}

int Company::getGetOnOffTime() const
{
    return getOnOffTime;
}

int Company::getNumberOfEvents() const
{
    return numberOfEvents;
}

void Company::runSimulation()
{

	while(Run)
	{






	}

   
}
