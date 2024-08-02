#include <Arduino.h>
#include "./headers/ButtonHandler.h"
#include "./headers/BLEHandler.h"
#include "./headers/Config.h"

ButtonHandler::ButtonHandler() : counter(0) {}

void ButtonHandler::checkButton() {
    int buttonState = digitalRead(PUSH_ONE_PIN);
    // sprintf(output, "1 => %d", buttonState);
    // Serial.println(output);
    // Serial.println(buttonState);
    if (buttonState == HIGH) {
        counter++;
        sprintf(buffer, "Button pressed (+) %d", counter);
        Serial.println(buffer);
        pCharacteristic->setValue(buffer);
        pCharacteristic->notify();
        delay(1000); // Evita múltiples conteos por un solo pulso del botón
    }
    int secondState = digitalRead(PUSH_SECOND_PIN);
    // sprintf(output, "2 => %d", secondState);
    // Serial.println(output);
    if (secondState == HIGH) {
        counter--;
        sprintf(buffer, "Button pressed (-) %d", counter);
        Serial.println(buffer);
        pCharacteristic->setValue(buffer);
        pCharacteristic->notify();
        delay(1000); // Evita múltiples conteos por un solo pulso del botón
    }
}
