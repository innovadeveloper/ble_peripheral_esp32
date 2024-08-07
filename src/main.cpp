#include <Arduino.h>
#include <config/config.h>

#include "./libraries/ble_client.h"

extern void setupButtons(
    const std::vector<Button> &buttonList,
    const std::function<void(const Button &, const bool isLongClick)> &closure);
extern void processButtonPressed(
    const Button &pressedButton,
    const bool isLongClick);

void setup()
{
  Serial.begin(9600);
  pinMode(PUSH_ONE_PIN, INPUT_PULLDOWN);
  pinMode(PUSH_SECOND_PIN, INPUT_PULLDOWN);
  // pinMode(2, OUTPUT);
  setupBLE();
}

// char buffer[100];
// Lee el estado del botón
std::vector<Button> buttons = {
    Button(SC_001_COMMAND, RESTART_COMMAND, PUSH_ONE_PIN),
    Button(SC_002_COMMAND, LC_002_COMMAND, PUSH_SECOND_PIN)
    // Button(SC_003_COMMAND, LC_003_COMMAND, PUSH_THIRD_PIN)
    };

void loop()
{
  setupButtons(buttons, [](const Button &button, const bool isLongClick)
               {
    processButtonPressed(button, isLongClick);
      delay(100); 
    });
}
