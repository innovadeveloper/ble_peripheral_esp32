#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>

const int buttonPin = 4;  // Pin del botón (GPIO04)
const int ledPin = 2;     // Pin del LED
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define PUSH_ONE_PIN        4
BLECharacteristic *pCharacteristic;

// const int buttonPin = 4;  // Pin del botón (GPIO04)
// const int ledPin = 2;     // Pin del LED
class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue();
      if (value.length() > 0) {
        Serial.print("\r\nNew value: ");
        for (int i = 0; i < value.length(); i++)
          Serial.print(value[i]);
        Serial.println();
      }
    }
};

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Lee el estado del botón
  int buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);

  if (buttonState == HIGH) {
    Serial.println("Click in button");
    digitalWrite(ledPin, HIGH);  // Enciende el LED
    delay(2000);
  } else {
    digitalWrite(ledPin, LOW);   // Apaga el LED
  }
  delay(100);
}
