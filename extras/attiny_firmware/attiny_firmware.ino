/**
 **************************************************
 *
 * @file        Template for attiny_firmware
 * @brief       Fill in sensor specific code.
 *

 *
 * @authors Zvonimir Haramustek for Soldered.com
 ***************************************************/

#include "easyC.h"
#include <Wire.h>

int addr = DEFAULT_ADDRESS;

void setup()
{
    initDefault();
    addr = getI2CAddress();

    Wire.begin(addr);
    Wire.onReceive(receiveEvent);
    Wire.onRequest(requestEvent);

    pinMode(PA4, INPUT);
}

void loop()
{
}


void receiveEvent(int howMany)
{
    while (1 < Wire.available())
    {
        char c = Wire.read();
    }

    char c = Wire.read();
}

void requestEvent()
{
    char c = digitalRead(PA4);
    Wire.write(&c, 1);
}