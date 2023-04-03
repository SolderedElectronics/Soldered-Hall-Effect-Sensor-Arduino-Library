/**
 **************************************************
 *
 * @file        digitalReadEasyC.ino
 * @brief       Example of using the easyC Digital Hall Effect sensor by Soldered Electronics
 *              For more info, see: solde.red/333081
 *
 *
 * @copyright GNU General Public License v3.0
 * @authors Robert Soric for Soldered.com
 ***************************************************/

#include "Hall-Effect-SOLDERED.h"

// For this example, connect the Hall Effect Sensor to your Dasduino board via easyC
// The default address is 0x30
// You may change the address via the switches on the front of the board
// In this table, 'x' represents a switch toggled 'UP'
// Note that on the physical switches 1 and 3 are swapped
// Address | 3 | 2 | 1 |
// 0x30    |   |   |   |
// 0x31    |   |   | x |
// 0x32    |   | x |   |
// 0x33    |   | x | x |
// 0x34    | x |   |   |
// 0x35    | x |   | x |
// 0x36    | x | x |   |
// 0x37    | x | x | x |

// To change the reading, place a magnet in front of the sensor
// getReading returns 1 (True) for a detected magnet and 0 (False) for no magnet detected
// If it's always reading 1, check connections and address

// Declare sensor object on default address
HallEffect_Digital_EasyC hall;

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);

    // Initialize sensor via EasyC (required!)
    hall.begin();

    // If you wish to use a custom address (e.g. 0x33), use
    // hall.begin(0x33);
}

void loop()
{
    // Read sensor
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
    delay(1000);
}
