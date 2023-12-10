#include "SimulationTime.h"
#include <iostream>
using namespace std;

SimulationTime::SimulationTime(int H,int M, int S) : current_hour(H), current_minute(M), current_second(S){}

SimulationTime::SimulationTime():current_hour(0), current_minute(0), current_second(0){}

void SimulationTime::advanceTime(int seconds) 
{
    current_second += seconds;

    while (current_second >= 60) 
    {
        current_minute++;
        current_second -= 60;
    }
    while (current_minute >= 60)
    {
        current_hour++;
        current_minute -= 60;
    }
    while (current_hour >= 24)
    {
        current_hour = 0;

        current_minute = 0;

        current_second = 0;
    }
}

void SimulationTime::printCurrentTime() const 
{
    cout << "Current Time: " << current_hour << ":" << current_minute << ":" << current_second <<endl;
}

void SimulationTime::setTime(int H, int M, int S)
{
    current_hour = H;

    current_minute = M;

    current_second = S;
}

int SimulationTime::getCurrentHour()
{
    return current_hour;
}

int SimulationTime::getCurrentMinute()
{
    return current_minute;
}

int SimulationTime::getCurrentSecond()
{
    return current_second;
}
