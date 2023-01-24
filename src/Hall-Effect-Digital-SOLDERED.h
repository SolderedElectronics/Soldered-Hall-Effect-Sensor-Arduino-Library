/**
 **************************************************
 *
 * @file        Hall-Effect-Digital-SOLDERED.h
 * @brief       Header file of Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333080
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#ifndef __HALL_EFFECT_DIGITAL_SOLDERED__
#define __HALL_EFFECT_DIGITAL_SOLDERED__

#include "Arduino.h"

/**
 *  @brief    Base class Digital Hall Effect Sensor
 *
 */
class HallEffect_Digital
{
  public:
    HallEffect_Digital(int _pin);
    bool getReading();

  private:
    int pin;
};

#endif
