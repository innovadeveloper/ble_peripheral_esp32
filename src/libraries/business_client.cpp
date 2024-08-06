#include "./config/config.h"
#include "./libraries/button.h"
#include <Arduino.h>
#include <stdio.h> // En lugar de <iostream>
#include <esp_system.h> // Incluye la biblioteca necesaria para usar esp_restart()

char buffer[100];
void processButtonPressed(
    const Button &pressedButton,
    const bool isLongClick)
{
    auto command = isLongClick? pressedButton.longClickCommand.c_str() : pressedButton.simpleClickCommand.c_str();
    // Imprimir los detalles del ButtonDTO
    sprintf(buffer, "type click %s, command : %s, pin : %d", 
    isLongClick? "large" : "short", 
    command,
    pressedButton.pin
    );

    Serial.println(buffer);
    if(isEquals(command, RESTART_COMMAND)){
        Serial.println("reiniciando");
        esp_restart();
        delay(1000);
    }
}
