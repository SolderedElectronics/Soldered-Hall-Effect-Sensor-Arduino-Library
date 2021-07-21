/**
 **************************************************
 *
 * @file        Generic-easyC-SOLDERED.cpp
 * @brief       Example functions to overload in base class.
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Zvonimir Haramustek for Soldered.com
 ***************************************************/


#include "Hall-Effect-SOLDERED.h"


/**
 * @brief                   Hall_Effect specific native constructor.
 *
 * @param int _pin          Example parameter.
 */
// Hall_Effect::Hall_Effect(int _pin)
// {
//     pin = _pin;
//     native = 1;
// }

/**
 * @brief                   Overloaded function for virtual in base class to initialize sensor specific.
 */
// void Hall_Effect::initializeNative()
// {
//     pinMode(pin, INPUT);
// }

/**
 * @brief                   Reads hall effect sensor value.
 *
 * @return                  Returns sensor value.
 */
bool Hall_Effect::digitalRead()
{
    char a;
    readRegister(0, &a, 1);

    return !a;
}
