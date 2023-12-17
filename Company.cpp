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

    int timestep = hour * 60 + minute;
    return new ArrivalEvent(timestep, id, passengerType, startStation, endStation, priority);
}

Event* Company::createLeaveEvent(ifstream& inputFile)
{
    
    int hour, minute, id;
    char colon;

    inputFile >> hour >> colon >> minute >> id;

    int timestep = hour * 60 + minute;
    return new LeaveEvent(timestep, id);
}



void Company::randomAssigning(int timestep)
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
            passenger->setFinishTime(timestep);
            passenger->setMovingTime(timestep);
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

        file << timestepToHHMM(passenger->getFinishTime()) << "\t\t\t" << passenger->getId() << "\t\t\t";
        file << timestepToHHMM(passenger->getArrivalTime()) << "\t\t\t" << timestepToHHMM(passenger->getWaitingTime()) << '\n';

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
    file << "Passenger Avg Wait time= " << timestepToHHMM(totalWaitingTime / totalPassengersCount) << "\n";
    file << "Auto-promoted passengers: " << (float)promotedPassengers / totalPassengersCount * 100.0 << "%\n";
}

string Company::timestepToHHMM(int timestep) 
{
    string hour = to_string(timestep / 60);
    string minute = to_string(timestep % 60);
    return hour + ":" + minute;
}

void Company::startSimulation()
{
    ui.getMode();
    int timestep = 240;

    while (!isAllListsEmpty() && timestep < 1320)
    {
        while (!events.IsEmpty() && events.Peek()->getTimeStep() == timestep) 
        {
            events.Pop()->execute(stations);
        }

        for (auto station : stations) 
        {
            promotedPassengers += station->promotePassengers(timestep, maxWaitingTime);
        }

        randomAssigning(timestep);

        timestep++;
        ui.printSimulationInfo(timestep, stations, finishedPassengers);
    }

    generateOutputFile();
    ui.displayEndMessage();
}
