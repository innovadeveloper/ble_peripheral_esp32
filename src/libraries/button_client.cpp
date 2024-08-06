#include "./config/config.h"
#include "./libraries/button.h"
#include <Arduino.h>

void setupButtons(
    const std::vector<Button> &buttonList,
    const std::function<void(const Button&, const bool isLongClick)> &closure)
{
    for (size_t i = 0; i < buttonList.size(); ++i)
    {
        Button button = buttonList[i];
        unsigned long startTime;  // Variable para almacenar el tiempo de inicio
        unsigned long elapsedTime;  // Variable para almacenar el tiempo transcurrido

        while (isPinHigh(button.pin))
        {
            startTime = millis();
            while (isPinHigh(button.pin))
            {
                elapsedTime = millis() - startTime;
            }
            closure(button, (elapsedTime > LONG_CLICK_TIME));
        }
    }
}
