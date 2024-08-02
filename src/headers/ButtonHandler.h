#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H

class ButtonHandler {
public:
    ButtonHandler();
    void checkButton();
    
private:
    int counter;
    char buffer[50];
    char output[50];
};

#endif // BUTTONHANDLER_H
