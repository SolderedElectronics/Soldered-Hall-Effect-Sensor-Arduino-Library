/**
 **************************************************
 *
 * @file        Hall-Effect-Analog-easyC-SOLDERED.h
 * @brief       Header file of EasyC Analog Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333082
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#ifndef __HALL_EFFECT_ANALOG_EASYC_SOLDERED__
#define __HALL_EFFECT_ANALOG_EASYC_SOLDERED__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

/**
 *  @brief    Base class Analog EasyC Hall Effect Sensor
 *
 */
class HallEffect_Analog_EasyC : public EasyC
{
  public:
    HallEffect_Analog_EasyC(){};
    uint16_t getRawReading();
    float getMilliTeslas();

  protected:
    void initializeNative(){};
};

#endif
