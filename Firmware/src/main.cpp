/**
 * @file main.cpp
 * @author Joe
 * @brief Source code for analog-clock-module
 */

// Core Libs
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>

// Other Libs
#include "ArduinoLog.h"

// Headers
#include "boardPins.h"
#include "constants.h"

// Hardware
Adafruit_NeoPixel pixelsRight(PIXELS_PER_QUAD, RIGHT_QUAD_PIN, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    // Setup serial
    delay(200);
    Serial.begin(115200);
    Serial.print("\n\n");

    // Setup logging
    Log.begin(LOG_LEVEL_VERBOSE, &Serial);
    long int _startupTime = millis();
    Log.infoln("Begin user code. Version %s", REVISION);

    // Hardware
    pixelsRight.begin();

    // Complete startup
    Log.infoln("Startup done, took %d ms", millis() - _startupTime);
}

void loop()
{
    // Main loop is scheduled by the RTOS (even when no libs are included)

    // Do nothing
    delay(100);
}
