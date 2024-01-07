#include "UI.h"

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

// Class implementation for UI
UI::UI() {
    ApplicationMode = Mode::Interactive;
    setMode();
}

void UI::setMode() {
    int modeNum = -1;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Please Choose Your Interface Mode: \n [1] For Interactive Mode \n [2] For Silent Mode" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cin >> modeNum;
    while (modeNum > 2 || modeNum < 1) {
        std::cout << "Please Enter A Valid Number: " << std::endl;
        std::cin >> modeNum;
    }
    switch (modeNum) {
        case 1:
            ApplicationMode = Mode::Interactive;
            break;
        case 2:
            ApplicationMode = Mode::Silent;
            break;
        default:
            ApplicationMode = Mode::Silent;
            break;
    }
}

Mode UI::GetCurrentMode() const {
    return ApplicationMode;
}

void UI::printMessage(std::string Message) const {
    if (ApplicationMode == Mode::Interactive) {
        IntercativeModeOutput(Message);
    }
    if (ApplicationMode == Mode::Silent) {
        StepByStepModeOutput(Message);
    }
}

void UI::IntercativeModeOutput(std::string Message) const {
    std::cout << Message << std::endl;
    _getch();
}

void UI::StepByStepModeOutput(std::string Message) const {
    std::cout << Message << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
