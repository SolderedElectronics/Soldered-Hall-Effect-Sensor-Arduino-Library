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
 */
uint16_t HallEffect_Analog::getReading()
{
#ifdef ESP32
    uint32_t value = analogReadMilliVolts(pin);
    return map(value, 142, 3166, 0, 1024);
#else
    return analogRead(pin);
#endif
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
    return 20.47 * (10 * (value / 1023.0) / 5.0 - 1);
}
