#pragma once
class Station
{
private:

	int station_number;

	int passenger_Count;



public:

	Station();

	Station(int num);

	void setStationNumber(int num);

	void setPassengerCount(int count);

	int getStationNumber();

	int getPassengerCount();



	

};

