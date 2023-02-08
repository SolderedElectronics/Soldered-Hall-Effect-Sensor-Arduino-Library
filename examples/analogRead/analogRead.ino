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
#define HALL_EFFECT_PIN A0

// For this example, connect the Hall Effect Sensor to your Dasduino board as such:
// VCC to VCC on Dasduino
// OUT to Pin HALL_EFFECT_PIN (can be changed according to your board)
// GND to GND

// To change the reading, place a magnet in front of the sensor
// getReading returns a uint16_t analogRead on the sensor pin
// The sensor outputs a value approximately in the middle of your analogRead range
// A higher number indicates a stronger positive magnetic force
// A lower number indicates a stronger negative magnetic force
// If it's always reading 0, check connections and if the HALL_EFFECT_PIN is free to be used as an analog input on your board
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
    // Read sensor and store to variable
    uint16_t hallReading = hall.getReading();
    float hallMilliTeslas = hall.getMilliTeslas();

    // Print sensor values to serial
    Serial.print("Analog Hall Effect raw sensor reading: ");
    Serial.println(hallReading);
    Serial.print("Analog Hall Effect sensor reading in milli Teslas: ");
    Serial.print(hallMilliTeslas);
    Serial.println(" mT\n");

    // Wait a bit until next measurement
    delay(1000);
}
