/**
 **************************************************
 *
 * @file        Hall-Effect-Digital-easyC-SOLDERED.h
 * @brief       Functions of EasyC Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333081
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-Digital-easyC-SOLDERED.h"

/**
 * @brief                   Reads hall effect sensor value via easyC
 *
 * @return                  Returns sensor value inverted (1 for magnet detected, 0 for no magnet)
 */
bool HallEffect_Digital_EasyC::getReading()
{
    // Reading register will always return two bytes
    // Both must be read but we're only interested in the first one
    char value[2];
    readRegister(0, value, 2);
    return !value[1];
}
