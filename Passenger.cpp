#include "Passenger.h"

Passenger::Passenger(string type, int id, int arrivalTime, int startStation, int endStation, int priority)
    : type(type), arrivalTime(arrivalTime), startStation(startStation), endStation(endStation), priority(priority), id(id)
{
    gettingTime = movingTime = finishTime = -1;
}

string Passenger::getType() const
{
    return type;
}

int Passenger::getId() const
{
    return id;
}

int Passenger::getArrivalTime() const 
{
    return arrivalTime;
}

int Passenger::getStartStation() const 
{
    return startStation;
}

int Passenger::getEndStation() const 
{
    return endStation;
}

int Passenger::getPriority() const 
{
    return priority;
}

int Passenger::getGettingTime() const 
{
    return gettingTime;
}

int Passenger::getMovingTime() const 
{
    return movingTime;
}

int Passenger::getWaitingTime() const 
{
    return movingTime - arrivalTime;
}

int Passenger::getTripTime() const 
{
    return finishTime - movingTime;
}

int Passenger::getFinishTime() const 
{
    return finishTime;
}

void Passenger::setMovingTime(int movingTime) 
{
    this->movingTime = movingTime;
}

void Passenger::setFinishTime(int finishTime) 
{
    this->finishTime = finishTime;
}

void Passenger::setGettingTime(int gettingTime)
{
    this->gettingTime = gettingTime;
}

void Passenger::setPriority(int priority) 
{
    this->priority = priority;
}
