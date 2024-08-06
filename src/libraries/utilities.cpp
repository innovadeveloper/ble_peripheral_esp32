#include "./config/config.h"
#include "./libraries/utilities.h"
#include <Arduino.h>
#include <cstring>

bool isPinHigh(int pin){
    return digitalRead(pin) == HIGH;
}

bool isEquals(const char* str1, const char* str2){
    return strcmp(str1, str2) == 0;
}
