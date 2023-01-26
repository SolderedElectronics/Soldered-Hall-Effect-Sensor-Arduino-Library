/**
 **************************************************
 *
 * @file        Hall-Effect-Digital-easyC-SOLDERED.h
 * @brief       Header file of EasyC Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333081
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#ifndef __HALL_EFFECT_DIGITAL_EASYC_SOLDERED__
#define __HALL_EFFECT_DIGITAL_EASYC_SOLDERED__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.hpp"

/**
 *  @brief                 Base class Digital EasyC Hall Effect Sensor
 *
 */
class HallEffect_Digital_EasyC : public EasyC
{
  public:
    HallEffect_Digital_EasyC(){};
    bool getReading();

  protected:
    void initializeNative(){};
};

#endif
