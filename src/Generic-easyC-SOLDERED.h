/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 *
 * @authors     @ soldered.com
 ***************************************************/

#ifndef __SENSOR__
#define __SENSOR__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

class Sensor : EasyC
{
  public:
    Sensor(int _pin);

  protected:
    void initializeNative();

  private:
    int pin;
};

#endif
