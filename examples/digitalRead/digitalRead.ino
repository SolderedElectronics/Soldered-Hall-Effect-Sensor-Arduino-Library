/**
 **************************************************
 *
 * @file        digitalRead.ino
 * @brief       Example of using the Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333080
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-SOLDERED.h"
#define HALL_EFFECT_PIN 5

// For this example, connect the Hall Effect Sensor to your Dasduino board as such:
// VCC to 3v3
// OUT to Pin 5 (can be changed below)
// GND to GND

// To change the reading, place a magnet in front of the sensor
// getReading Reads 1 (True) for a detected magnet and 0 (False) for no magnet detected
// If it's always reading 0, check connections

// Declare sensor object
HallEffect_Digital hall(HALL_EFFECT_PIN);

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);
}

void loop()
{
    bool hallReading = hall.getReading();

    // Print sensor value to serial
    Serial.print("Digital Hall Effect Sensor reading: ");
    Serial.println(hallReading);

    // Print a string depending on the measurement result
    if(hallReading)
    {
        Serial.println("Magnet detected!\n");
    }
    else
    {
        Serial.println("No magnet detected.\n");
    }
    
    // Wait a bit until next measurement
    delay(2000);
}
