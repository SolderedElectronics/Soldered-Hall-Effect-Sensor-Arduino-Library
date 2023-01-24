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
    int c = 0;
    char a[2];
    
    c = analogRead(PA4);
    a[1] = c >> 8;
    a[0] = c & 0xFF;
    Wire.write(a, 2);
}