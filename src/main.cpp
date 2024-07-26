// #include <Arduino.h>
// #include <BLEDevice.h>
// #include <BLEServer.h>
// #include <BLECharacteristic.h>

// const int buttonPin = 4;  // Pin del botón (GPIO04)
// const int ledPin = 2;     // Pin del LED

// void setup() {
//   Serial.begin(9600);
//   pinMode(buttonPin, INPUT_PULLDOWN);
//   pinMode(ledPin, OUTPUT);
// }

// void loop() {
//   // Lee el estado del botón
//   int buttonState = digitalRead(buttonPin);
//   Serial.println(buttonState);

//   if (buttonState == HIGH) {
//     Serial.println("Click in button");
//     digitalWrite(ledPin, HIGH);  // Enciende el LED
//     delay(2000);
//   } else {
//     digitalWrite(ledPin, LOW);   // Apaga el LED
//   }
//   delay(100);
// }

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

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

  BLEDevice::init("ESP32 BLE example");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new MyCallbacks());

  pCharacteristic->setValue("Hello World");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}
int counter;
char buffer[50];

void loop() {
  delay(100);
  int buttonState = digitalRead(PUSH_ONE_PIN);
  if (buttonState == HIGH) {
    counter += 1;
    sprintf(buffer, "Button pressed %d", counter);
    Serial.println(buffer);
    pCharacteristic->setValue(buffer);
    pCharacteristic->notify();
    delay(1000);
  }
}