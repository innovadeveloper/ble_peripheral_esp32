#ifndef BLE_CLIENT_H
#define BLE_CLIENT_H

#include "./config/config.h"
#include "./libraries//button.h"
#include <vector>
#include <functional>

void setupBLE();

// void findButtonDTO(
//     const std::vector<Button>& buttonList,
//     const std::function<void(const Button&)>& closure);

#endif // BLE_CLIENT_H
