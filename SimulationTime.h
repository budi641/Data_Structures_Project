#pragma once

class SimulationTime
{
private:

    int current_hour;

    int current_minute;

    int current_second;

public:

    SimulationTime(int H, int M, int S);

    SimulationTime();

    void advanceTime(int seconds);

    void printCurrentTime() const;

    void setTime(int H, int M, int S);

    int getCurrentHour();

    int getCurrentMinute();

    int getCurrentSecond();

};

