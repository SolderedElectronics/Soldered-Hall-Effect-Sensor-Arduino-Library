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
 * @brief                   Constructor of HallEffect_Digital_EasyC with a custom address
 * 
 * @param                   byte _addr
 *                          Custom address (view examples/digitalRead_easyC for more info)
 */
HallEffect_Digital_EasyC::HallEffect_Digital_EasyC(byte _addr)
{

}

/**
 * @brief                   Reads hall effect sensor value via easyC
 *
 * @return                  Returns sensor value inverted (1 for magnet detected, 0 for no magnet)
 */
bool HallEffect_Digital_EasyC::getReading()
{
    char a;
    readRegister(0, &a, 1);
    return !a;
}
