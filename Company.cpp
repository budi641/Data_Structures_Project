#include "Company.h"

Company::Company() 
{
    maxWaitingTime = -1;

    promotedPassengers = promotedPassengers = numberOfStations = timeBetweenStations = numberOfWBus = numberOfMBus = capacityWBus = capacityMBus = tripsBeforeCheckup = checkupDurationWBus = checkupDurationMBus = getOnOffTime = numberOfEvents = 0;
}


void Company::readInputFile(string inputFileName)
{
    ifstream inputFile(inputFileName);

    inputFile >> numberOfStations >> timeBetweenStations;

    inputFile >> numberOfWBus >> numberOfMBus;

    inputFile >> capacityWBus >> capacityMBus;

    inputFile >> tripsBeforeCheckup >> checkupDurationWBus >> checkupDurationMBus;

    inputFile >> maxWaitingTime >> getOnOffTime;

    inputFile >> numberOfEvents;

    numberOfStations++;

    while (numberOfStations--)
    {
        stations.InsertEnd(new Station());
    }
    numberOfEvents++;

    while (numberOfEvents--)
    {
        char eventType;
        inputFile >> eventType;
        Event* tempEvent = (eventType == 'A') ? createArrivalEvent(inputFile) : createLeaveEvent(inputFile);
        events.Push(tempEvent);

        
    }
    inputFile.close();


}




Event* Company::createArrivalEvent(ifstream& inputFile)
{
    string passengerType;
    int hour, minute, id, startStation, endStation, priority = -1;
    char colon;

    inputFile >> passengerType >> hour >> colon >> minute >> id >> startStation >> endStation;

    if (passengerType == "SP")
    {
        string subType;
        inputFile >> subType;
        if (subType == "aged")
            priority = 2;
        else if (subType == "POD")
            priority = 1;
        else
            priority = 0;
    }

    int timeStamp = hour * 60 + minute;
    return new ArrivalEvent(timeStamp, id, passengerType, startStation, endStation, priority);
}

Event* Company::createLeaveEvent(ifstream& inputFile)
{
    
    int hour, minute, id,start;
    char colon;

    inputFile >> hour >> colon >> minute >> id>>start;

    int timeStamp = hour * 60 + minute;
    return new LeaveEvent(timeStamp, id,start);
}



void Company::randomAssigning(int timeStamp)
{
    for (auto station : stations) 
    {
        int randomNumber = rand() % 100 + 1;
        Passenger* passenger = nullptr;

        if (randomNumber < 21) 
        {
            passenger = station->removeTopForwardSpecialPassenger();
            if (!passenger) 
            {
                passenger = station->removeTopBackwardSpecialPassenger();
            }
        }
        else if (randomNumber < 31) 
        {
            passenger = station->removeTopForwardWheelPassenger();
            if (!passenger) 
            {
                passenger = station->removeTopBackwardWheelPassenger();
            }
        }
        else if (randomNumber < 61) 
        {
            passenger = station->removeTopForwardNormalPassenger();
            if (!passenger) 
            {
                passenger = station->removeTopBackwardNormalPassenger();
            }
        }

        if (passenger) 
        {
            passenger->setFinishTime(timeStamp);
            passenger->setMovingTime(timeStamp);
            finishedPassengers.Push(passenger);
        }
    }
}

bool Company::isAllListsEmpty()
{
    for (auto station : stations) 
    {
        if (!station->hasWaitingPassengers())
            return false;
    }

    return events.IsEmpty();
}

void Company::generateOutputFile() 
{
    ofstream file("output.txt");
    file << "FT\t\t\tID\t\t\tAT\t\t\tWT\n";
    int npCount = 0, spCount = 0, wpCount = 0;
    int totalWaitingTime = 0;

    while (!finishedPassengers.IsEmpty()) 
    {
        Passenger* passenger = finishedPassengers.Pop();

        file << timeStampToHHMM(passenger->getFinishTime()) << "\t\t\t" << passenger->getId() << "\t\t\t";
        file << timeStampToHHMM(passenger->getArrivalTime()) << "\t\t\t" << timeStampToHHMM(passenger->getWaitingTime()) << '\n';

        totalWaitingTime += passenger->getWaitingTime();

        string type = passenger->getType();
        if (type == "NP")
            npCount++;
        else if (type == "SP")
            spCount++;
        else
            wpCount++;
    }

    float totalPassengersCount = npCount + spCount + wpCount;
    file << "Passengers: " << totalPassengersCount << "   [NP: " << npCount << ", SP: " << spCount << ", WP: " << wpCount << "]\n";
    file << "Passenger Avg Wait time= " << timeStampToHHMM(totalWaitingTime / totalPassengersCount) << "\n";
    file << "Auto-promoted passengers: " << (float)promotedPassengers / totalPassengersCount * 100.0 << "%\n";
}

string Company::timeStampToHHMM(int timeStamp) 
{

    string hour = to_string(timeStamp / 60);
    string minute = to_string(timeStamp % 60);
    return hour + ":" + minute;
}

void Company::startSimulation()
{
    ui.getMode();
    int timeStamp = 240;

    while (!isAllListsEmpty() && timeStamp < 1320)
    {
        while (!events.IsEmpty() && events.Peek()->getTimeStep() == timeStamp) 
        {
            events.Pop()->execute(stations);
        }

        for (auto station : stations) 
        {
            promotedPassengers += station->promotePassengers(timeStamp, maxWaitingTime);
        }

        randomAssigning(timeStamp);

        timeStamp++;
        ui.printSimulationInfo(timeStamp, stations, finishedPassengers);
    }

    generateOutputFile();
    ui.displayEndMessage();
}
