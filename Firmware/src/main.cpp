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
Adafruit_NeoPixel pixelsRight(PIXELS_PER_QUAD, 16, NEO_GRB + NEO_KHZ800);
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
    pixelsRight.show();
    pixelsRight.setBrightness(50);

    // Complete startup
    Log.infoln("Startup done, took %d ms", millis() - _startupTime);
}

// Main loop is scheduled by the RTOS (even when no libs are included)
void loop()
{
    pixelsRight.clear();

    for (int i = 0; i < PIXELS_PER_QUAD; i++)
    { // For each pixel...

        // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
        // Here we're using a moderately bright green color:
        pixelsRight.setPixelColor(i, pixelsRight.Color(255, 255, 255));

        pixelsRight.show(); // Send the updated pixel colors to the hardware.

        delay(50); // Pause before next pass through loop
    }
}
