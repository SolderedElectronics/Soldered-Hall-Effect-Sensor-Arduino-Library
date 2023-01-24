/**
 **************************************************
 *
 * @file        Hall-Effect-Analog-easyC-SOLDERED.h
 * @brief       Functions of EasyC Analog Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333082
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-Analog-easyC-SOLDERED.h"

/**
 * @brief                   Reads hall effect raw sensor value via easyC
 *
 * @return                  Returns raw reading as a float
 */
int HallEffect_Analog_EasyC::getRawReading()
{
    // Reading register will always return two bytes
    // Both must be read but we're only interested in the first one
    char raw[2];
    readRegister(ANALOG_READ_REG, raw, 2 * sizeof(uint8_t));
    uint16_t value = raw[0] | (raw[1]) << 8;
    return value;
}

/**
 * @brief                   Reads hall effect calculated milli Teslas value via easyC
 *
 * @return                  Returns calculated milli Teslas
 */
float HallEffect_Analog_EasyC::getMilliTeslas()
{
    uint16_t value = getRawReading();
    return 20.47 * (10 * (value / 1023.0) / 5.0 - 1);
}
