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
uint16_t HallEffect_Analog_EasyC::getRawReading()
{
    // Reading register will always return two bytes
    uint8_t raw[2];
    readRegister(ANALOG_READ_REG, (char *)raw, 2);
    uint16_t value = ( (uint8_t)raw[1] << 8) | (uint8_t)raw[0];
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
