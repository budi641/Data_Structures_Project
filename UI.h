#pragma once

#include <string>
#include <iostream>

// Enumerations for different event and passenger types
enum Event_Type
{
    Arrival,
    leave,
    
};

enum Passenger_Type {
    NP,	// Normal Passenger Type
    SP,	// Special Passenger Type
    wp	// Wheel_chair Passenger Type
};

enum Bus_Type {
    MB,	// Mixed Bus
    WB,	// Wheel Bus
   
};

enum Mode {
    Interactive,
    Silent,
  
};

// Class representing the UI
class UI {
private:
    Mode ApplicationMode;
    
public:
    UI();
    void setMode();
    Mode GetCurrentMode() const;
    void printMessage(std::string message) const;
    void IntercativeModeOutput(std::string message) const;
    void StepByStepModeOutput(std::string message) const;
};
