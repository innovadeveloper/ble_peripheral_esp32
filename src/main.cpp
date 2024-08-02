#include <Arduino.h>
// #include <BLEDevice.h>
// #include <BLEUtils.h>
// #include <BLEServer.h>

// #define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
// #define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
// #define PUSH_ONE_PIN        4

#include "./headers/ButtonHandler.h"
#include "./headers/BLEHandler.h"
#include "./headers/Config.h"

// Instancias de las clases
BLEHandler bleHandler;
ButtonHandler buttonHandler;

void setup() {
  Serial.begin(9600);
  pinMode(PUSH_ONE_PIN, INPUT);
  pinMode(PUSH_SECOND_PIN, INPUT);
  
  bleHandler.setupBLE();
}

void loop() {
  delay(100);
  buttonHandler.checkButton();
}