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
 *                          Pin of the sensor (has to support AnalogRead)
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
 * @note                    The value will be around 1845 for no magnet detected.
 *                          It will increase towards 4095 (analogRead maximum) if a + polarity magnet is detected
 *                          And it will decrease towards 0 if a - polarity magnet is detected
 */
uint16_t HallEffect_Analog::getReading()
{
    return analogRead(pin);
}
