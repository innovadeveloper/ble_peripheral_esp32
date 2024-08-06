#include <Arduino.h>
#include <config/config.h>

#include "./libraries/ble_client.h"

extern void setupButtons(
    // const std::vector<Button> &buttonList,
    const std::function<void(const Button &)> &closure);

void setup() {
  Serial.begin(9600);
  // pinMode(buttonPin, INPUT_PULLDOWN);
  // pinMode(ledPin, OUTPUT);
}



void loop() {
  // Lee el estado del botón
  int buttonState = digitalRead(1);
  Serial.println(buttonState);
  setupBLE();
  // if (buttonState == HIGH) {
  //   Serial.println("Click in button");
  //   digitalWrite(ledPin, HIGH);  // Enciende el LED
  //   delay(2000);
  // } else {
  //   digitalWrite(ledPin, LOW);   // Apaga el LED
  // }
  delay(100);
}
