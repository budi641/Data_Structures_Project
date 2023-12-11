#include "Station.h"
#include "QueueADT.h"
#include "LinkedList.h"
#include "PriorityQueue.h"





Station::Station()
{
	station_number = 0;

	passenger_Count = 0;

}

Station::Station(int num)
{
	station_number = num;

	passenger_Count = 0;

}

void Station::setStationNumber(int num)
{
	station_number = num;

}

void Station::setPassengerCount(int count)
{
	passenger_Count = count;
}

int Station::getStationNumber()
{
	return station_number;
}

int Station::getPassengerCount()
{
	return passenger_Count;
}

