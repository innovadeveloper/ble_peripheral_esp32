#ifndef BUTTON_H
#define BUTTON_H

#include <string>

struct Button {
    std::string simpleClickCommand;
    std::string longClickCommand;
    int pin;

    // Constructor
    Button(const std::string& simpleClickCommand, const std::string& longClickCommand, int pin) : simpleClickCommand(simpleClickCommand), longClickCommand(longClickCommand), pin(pin) {}
};

#endif // BUTTON_H