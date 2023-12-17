#include "Station.h"

void Station::addPassenger(Passenger* passenger) 
{
    string passengerType = passenger->getType();

    if (passengerType == "NP")
    {
        // Normal Passenger
        if (passenger->getStartStation() < passenger->getEndStation()) 
        {
            waitingForwardNormalPassengers.InsertEnd(passenger);
        }
        else 
        {
            waitingBackwardNormalPassengers.InsertEnd(passenger);
        }
    }
    else if (passengerType == "SP")
    {
        // Special Passenger
        if (passenger->getStartStation() < passenger->getEndStation()) 
        {
            waitingForwardSpecialPassengers.Insert(passenger, passenger->getPriority());
        }
        else 
        {
            waitingBackwardSpecialPassengers.Insert(passenger, passenger->getPriority());
        }
    }
    else if (passengerType == "WP") 
    {
        // Wheel Passenger
        if (passenger->getStartStation() < passenger->getEndStation()) 
        {
            waitingForwardWheelPassengers.Push(passenger);
        }
        else 
        {
            waitingBackwardWheelPassengers.Push(passenger);
        }
    }
}

int Station::promotePassengers(int timestep, int maxWaitingTime) 
{
    int promotedPassengersCount = 0;
    Queue<Passenger*> promotedPassengers;

    for (auto passenger : waitingForwardNormalPassengers) 
    {
        int passengerWaitingTime = timestep - passenger->getArrivalTime();
        if (passengerWaitingTime > maxWaitingTime)
        {
            promotedPassengersCount++;
            promotedPassengers.Push(passenger);
        }
    }

    while (!promotedPassengers.IsEmpty()) 
    {
        Passenger* passenger = promotedPassengers.Pop();
        waitingForwardNormalPassengers.Remove(passenger);
        passenger->setPriority(2);
        waitingForwardSpecialPassengers.Insert(passenger, 2);
    }

    for (auto passenger : waitingBackwardNormalPassengers) 
    {
        int passengerWaitingTime = timestep - passenger->getArrivalTime();
        if (passengerWaitingTime > maxWaitingTime) 
        {
            promotedPassengersCount++;
            promotedPassengers.Push(passenger);
        }
    }

    while (!promotedPassengers.IsEmpty()) 
    {
        Passenger* passenger = promotedPassengers.Pop();
        waitingBackwardNormalPassengers.Remove(passenger);
        passenger->setPriority(2);
        waitingBackwardSpecialPassengers.Insert(passenger, 2);
    }

    return promotedPassengersCount;
}

Passenger* Station::removeTopForwardNormalPassenger() 
{

    return waitingForwardNormalPassengers.IsEmpty() ? nullptr : waitingForwardNormalPassengers.RemoveAt(0);
}

Passenger* Station::removeTopBackwardNormalPassenger() 
{

    return waitingBackwardNormalPassengers.IsEmpty() ? nullptr : waitingBackwardNormalPassengers.RemoveAt(0);
}

Passenger* Station::removeTopForwardSpecialPassenger() 
{
    return waitingForwardSpecialPassengers.IsEmpty() ? nullptr : waitingForwardSpecialPassengers.Pop();
}

Passenger* Station::removeTopBackwardSpecialPassenger() 
{
    return waitingBackwardSpecialPassengers.IsEmpty() ? nullptr : waitingBackwardSpecialPassengers.Pop();
}

Passenger* Station::removeTopForwardWheelPassenger() 
{
    return waitingForwardWheelPassengers.IsEmpty() ? nullptr : waitingForwardWheelPassengers.Pop();
}

Passenger* Station::removeTopBackwardWheelPassenger() 
{
    return waitingBackwardWheelPassengers.IsEmpty() ? nullptr : waitingBackwardWheelPassengers.Pop();
}

void Station::passengerLeave(int id) 
{
    for (auto p : waitingBackwardNormalPassengers) 
    {
        if (p->getId() == id) 
        {
            waitingBackwardNormalPassengers.Remove(p);
            return;
        }
    }

    for (auto p : waitingForwardNormalPassengers) 
    {
        if (p->getId() == id) {
            waitingForwardNormalPassengers.Remove(p);
            return;
        }
    }
}

bool Station::hasWaitingPassengers() 
{
    return waitingForwardNormalPassengers.IsEmpty() &&
        waitingBackwardNormalPassengers.IsEmpty() &&
        waitingForwardSpecialPassengers.IsEmpty() &&
        waitingBackwardSpecialPassengers.IsEmpty() &&
        waitingForwardWheelPassengers.IsEmpty() &&
        waitingBackwardWheelPassengers.IsEmpty();
}

string Station::info()
{
    string ret = "";

    string types[3] = { "pregnant", "POD", "aged" };

    int spCount = waitingBackwardSpecialPassengers.Size() + waitingForwardSpecialPassengers.Size(),
        wpCount = waitingBackwardWheelPassengers.Size() + waitingForwardWheelPassengers.Size(),
        npCount = waitingBackwardNormalPassengers.Size() + waitingForwardNormalPassengers.Size();
    // start SP
    ret += to_string(spCount) + " Waiting SP: FWD[";

    for (auto passenger : waitingForwardSpecialPassengers) {
        ret += to_string(passenger->getId()) + "(" + types[passenger->getPriority()] + "), ";
    }

    ret += "] BCK[";

    for (auto passenger : waitingBackwardSpecialPassengers) {
        ret += to_string(passenger->getId()) + "(" + types[passenger->getPriority()] + "), ";
    }

    ret += "]\n";
    // end SP

    // start WP
    ret += to_string(wpCount) + " Waiting WP: FWD[";

    for (auto passenger : waitingForwardWheelPassengers) {
        ret += to_string(passenger->getId()) + ", ";
    }

    ret += "] BCK[";

    for (auto passenger : waitingBackwardWheelPassengers) {
        ret += to_string(passenger->getId()) + "(, ";
    }

    ret += "]\n";
    // end WP

    //start NP
    ret += to_string(npCount) + " Waiting NP: FWD[";

    for (auto passenger : waitingForwardNormalPassengers) {
        ret += to_string(passenger->getId()) + ", ";
    }

    ret += "] BCK[";

    for (auto passenger : waitingBackwardNormalPassengers) {
        ret += to_string(passenger->getId()) + "(, ";
    }

    ret += "]\n";
    //end NP
    return ret;
}
    // ... (unchanged)

