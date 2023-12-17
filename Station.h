#pragma once
#include "LinkedList.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "Passenger.h"

class Station 
{
private:
    LinkedList<Passenger*> waitingForwardNormalPassengers;
    LinkedList<Passenger*> waitingBackwardNormalPassengers;
    PriorityQueue<Passenger*> waitingForwardSpecialPassengers;
    PriorityQueue<Passenger*> waitingBackwardSpecialPassengers;
    Queue<Passenger*> waitingForwardWheelPassengers;
    Queue<Passenger*> waitingBackwardWheelPassengers;

public:
    void addPassenger(Passenger* passenger);
    int promotePassengers(int timestep, int maxWaitingTime);
    Passenger* removeTopForwardNormalPassenger();
    Passenger* removeTopBackwardNormalPassenger();
    Passenger* removeTopForwardSpecialPassenger();
    Passenger* removeTopBackwardSpecialPassenger();
    Passenger* removeTopForwardWheelPassenger();
    Passenger* removeTopBackwardWheelPassenger();
    void passengerLeave(int id);
    bool hasWaitingPassengers();
    string info();
};
