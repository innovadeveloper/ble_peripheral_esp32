#ifndef CONFIG_H
#define CONFIG_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLECharacteristic.h>

#include <vector>
#include <functional>

#include "./libraries/utilities.h"

#include <string>
#include "./libraries/button.h" // Incluye la definición de ButtonDTO

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define PUSH_ONE_PIN 36
#define PUSH_SECOND_PIN 39
#define PUSH_THIRD_PIN 34
#define LONG_CLICK_TIME 2000

// commands
#define RESTART_COMMAND "RESTART"   // -> LC_001
#define SC_001_COMMAND "SC001"
#define SC_002_COMMAND "SC002"
#define SC_003_COMMAND "SC003"
#define LC_001_COMMAND "LC001"
#define LC_002_COMMAND "LC002"
#define LC_003_COMMAND "LC003"

#endif // CONFIG_H
