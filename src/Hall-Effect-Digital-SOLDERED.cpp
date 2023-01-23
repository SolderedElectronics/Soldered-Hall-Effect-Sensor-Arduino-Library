/**
 **************************************************
 *
 * @file        Hall-Effect-Digital-SOLDERED.cpp
 * @brief       Functions of Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333080
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-Digital-SOLDERED.h"

/**
 * @brief                   Constructor of HallEffect_Digital
 * 
 * @param                   int _pin
 *                          Pin of the sensor
 */
HallEffect_Digital::HallEffect_Digital(int _pin)
{
    pin = _pin;
    pinMode(pin, INPUT_PULLUP);
}

/**
 * @brief                   Reads hall effect sensor value
 *
 * @return                  Returns sensor value inverted (1 for magnet detected, 0 for no magnet)
 */
bool HallEffect_Digital::getReading()
{
    return !digitalRead(pin);
}
