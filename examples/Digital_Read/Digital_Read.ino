/**
 **************************************************
 *
 * @file        Digital_Read.ino
 * @brief       Example of digital read function for SOLDERED Hall Effect board, see more at solde.red/333081
 *
 *
 *
 * @authors Zvonimir Haramustek for Soldered.com
 ***************************************************/

#include "Hall-Effect-SOLDERED.h"

// Declare sensor object
Hall_Effect h;

void setup()
{
    // Initialize sensor
    h.begin();

    // Initialize serial communication
    Serial.begin(115200);
}

void loop()
{
    // Print sensor value to serial
    Serial.print("Hall Effect Sensor: ");
    Serial.println(h.digitalRead());

    delay(1000);
}
