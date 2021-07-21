/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.h
 * @brief       Header file for sensor specific code.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Zvonimir Haramustek for Soldered.com
 ***************************************************/

#ifndef __SENSOR__
#define __SENSOR__

#include "Arduino.h"
#include "libs/Generic-easyC/easyC.h"

class Hall_Effect : public EasyC
{
  public:
    // Hall_Effect(int _pin);
    Hall_Effect(){};

    bool digitalRead();

  protected:
    void initializeNative(){};

  private:
    // int pin;
};

#endif
