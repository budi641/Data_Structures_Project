#pragma once
#include"SimulationTime.h"
#include"Passenger.h"
#include"Bus.h"
#include"Station.h"
#include"Event.h"
#include"LeaveEvent.h"
#include"ArrivalEvent.h"
#include"UI.h"
#include<iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "ArrayQueue.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

class Company
{
private:

	bool Run;

	SimulationTime GlobalTime;

	UI IO_Manager;

	Station* stations;

	ArrayQueue<Event*>* Events;




public:

	Company();

	void runSimulation();
};

