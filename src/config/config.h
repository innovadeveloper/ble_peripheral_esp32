#ifndef CONFIG_H
#define CONFIG_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>

// #include <vector>
#include <string>
#include "./libraries/button.h" // Incluye la definición de ButtonDTO

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define PUSH_ONE_PIN 34
#define PUSH_SECOND_PIN 35
#define PUSH_THIRD_PIN 32

#endif // CONFIG_H
