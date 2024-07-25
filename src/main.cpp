#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>

const int buttonPin = 4;  // Pin del botón (GPIO04)
const int ledPin = 2;     // Pin del LED

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

// #include <Arduino.h>

// const int ledPin = 2;  // Pin al que está conectado el LED (ajusta según tu placa)

// void setup() {
//   pinMode(ledPin, OUTPUT);  // Configura el pin del LED como salida
// }

// void loop() {
//   digitalWrite(ledPin, HIGH);  // Enciende el LED
//   delay(2000);  // Espera 2 segundos
//   digitalWrite(ledPin, LOW);   // Apaga el LED
//   delay(5000);  // Espera 5 segundos
// }
