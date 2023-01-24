/**
 **************************************************
 *
 * @file        Hall-Effect-Analog-SOLDERED.h
 * @brief       Header file of Analog Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333079
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#ifndef __HALL_EFFECT_ANALOG_SOLDERED__
#define __HALL_EFFECT_ANALOG_SOLDERED__

#include "Arduino.h"

/**
 *  @brief    Base class Analog Hall Effect Sensor
 *
 */
class HallEffect_Analog
{
  public:
    HallEffect_Analog(int _pin);
    uint16_t getReading();
    float getMilliTeslas();

  private:
    int pin;
};

#endif
