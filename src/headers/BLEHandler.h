#ifndef BLEHANDLER_H
#define BLEHANDLER_H

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

extern BLECharacteristic *pCharacteristic;  // Declaración externa de pCharacteristic

class BLEHandler {
public:
    void setupBLE();
};

#endif // BLEHANDLER_H
