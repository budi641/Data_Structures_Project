#pragma once
#include <string>
using namespace std;

class Passenger 
{
private:
    string type;
    int id;
    int arrivalTime;
    int startStation;
    int endStation;
    int priority;
    int gettingTime;
    int movingTime;
    int finishTime;

public:
    Passenger(string type, int id, int arrivalTime, int startStation, int endStation, int priority);
    string getType() const;
    int getId() const;
    int getArrivalTime() const;
    int getStartStation() const;
    int getEndStation() const;
    int getPriority() const;
    int getGettingTime() const;
    int getMovingTime() const;
    int getWaitingTime() const;
    int getTripTime() const;
    int getFinishTime() const;
    void setMovingTime(int movingTime);
    void setFinishTime(int finishTime);
    void setGettingTime(int gettingTime);
    void setPriority(int priority);
};
