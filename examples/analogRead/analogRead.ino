/**
 **************************************************
 *
 * @file        analogRead.ino
 * @brief       Example of using the Analog Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333079
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-SOLDERED.h"
#define HALL_EFFECT_PIN 4

// For this example, connect the Hall Effect Sensor to your Dasduino board as such:
// VCC to 3v3
// OUT to Pin 5 (can be changed below)
// GND to GND

// To change the reading, place a magnet in front of the sensor
// getReading returns a uint16_t analogRead of the sensor
// The sensor outputs approx 1.65V by default
// A higher number indicates a stronger magnetic force
// If it's always reading 0, check connections and if the HALL_EFFECT_PIN can be used as an analog input on your board
// For more info, see: https://www.silabs.com/documents/public/data-sheets/si721x-data-sheet.pdf

// Declare sensor object
HallEffect_Analog hall(HALL_EFFECT_PIN);

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);
}

void loop()
{
    uint16_t hallReading = hall.getReading();

    // Print sensor value to serial
    Serial.print("Analog Hall Effect Sensor reading: ");
    Serial.println(hallReading);
    Serial.println(""); // Newline

    // Wait a bit until next measurement
    delay(500);
}
