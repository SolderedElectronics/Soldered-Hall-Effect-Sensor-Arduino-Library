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
 * @return                  Returns a unit16_t sensor reading value.
 *
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
    // Fix for ESP32's ADC
#ifdef ESP32
    if(value >= 2710)
    {
        return (value - 2710.0) * (20.47 - 0.0) / (4095.0 - 2710.0) + 0.0;
    }
    else
    {
        return (value) * (20.47) / (2710.0) - 20.47;
    }
#else
    return 20.47 * (NUM_BITS * (value / (ADC_MAX - 1)) / VOLTAGE_RES - 1);
#endif
}
