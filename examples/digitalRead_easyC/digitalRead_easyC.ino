/**
 **************************************************
 *
 * @file        digitalRead_easyC.ino
 * @brief       Example of using the easyC Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333081
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-SOLDERED.h"
#define HALL_EFFECT_PIN 5

// For this example, connect the Hall Effect Sensor to your Dasduino board via easyC
// The default address is 0x30
// You may change the address via the switches on the front of the board
// In this table, 'x' represents a switch toggled 'UP'
// Address | 1 | 2 | 3 |
// 0x30    |   |   |   |
// 0x31    |   |   | x |
// 0x32    |   | x |   |
// 0x33    |   | x | x |
// 0x34    | x |   |   |
// 0x35    | x |   | x |
// 0x36    | x | x |   |
// 0x37    | x | x | x |

// To change the reading, place a magnet in front of the sensor
// getReading Reads 1 (True) for a detected magnet and 0 (False) for no magnet detected
// If it's always reading 0, check connections

// Declare sensor object on default address
HallEffect_Digital_EasyC hall;

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
