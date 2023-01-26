/**
 **************************************************
 *
 * @file        Hall-Effect-Analog-SOLDERED.cpp
 * @brief       Functions of Analog Hall Effect sensor by Soldered Electronics
 *              For more info see: solde.red/333079
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-Analog-SOLDERED.h"

/**
 * @brief                   Constructor of HallEffect_Analog
 *
 * @param                   int _pin
 *                          Pin of the sensor (has to support analogRead)
 */
HallEffect_Analog::HallEffect_Analog(int _pin)
{
    pin = _pin;
    pinMode(pin, INPUT);
}

/**
 * @brief                   Reads hall effect sensor value
 *
 * @return                  Returns a unit16_4 sensor reading value.
 *
 * @note                    For no magnet, the value will be around the middle of your analogRead range, which depends
 * on your board. When a positive or negative magnet field is detected it will increase or decrease accordingly until it
 * reaches the maximum or minimum.
 */
uint16_t HallEffect_Analog::getReading()
{
    return analogRead(pin);
}

/**
 * @brief                   Reads hall effect calculated milli Teslas value
 *
 * @note                    The reading is calculated differently depending on your board's ADC. You may need to adjust
 *                          the calculation.
 *
 * @return                  float value of calculated milli Teslas
 */
float HallEffect_Analog::getMilliTeslas()
{

    float value = float(getReading());

#ifdef ESP32
    // For Dasduino ConnectPlus
    // Mapping values to correct ones
    float milliTeslas;
    if (value >= 2686.0)
    {
        milliTeslas = (value - 2686.0) * (20.35 - 0.00) / (4096.00 - 2686.0) + 0.00;
    }
    else
    {
        milliTeslas = (value - 0.00) * (0.00 - (-20.35)) / (2686.0 - 0.00) - 20.35;
    }

    return milliTeslas;
#else
    return 20.47 * (10 * (value / 1023.0) / 5.0 - 1);
#endif
}
