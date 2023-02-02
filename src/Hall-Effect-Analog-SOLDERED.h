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
 * Different boards use different ADC's with a different range and resolution
 */
#ifdef __AVR__

#define VOLTAGE_RES 5
#define ADC_MAX     1024
#define NUM_BITS    10

#elif ESP32

#define VOLTAGE_RES 3.3
#define ADC_MAX     4096
#define NUM_BITS    12

#elif ESP8266

#define VOLTAGE_RES 3.3
#define ADC_MAX     1024
#define NUM_BITS    10

#else

#define VOLTAGE_RES 5
#define ADC_MAX     1024
#define NUM_BITS    10

#endif

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
