// Include the necessary libraries
#include <Arduino.h>

// Define the pin for the onboard LED
const int ledPin = 13; // Pin number for the LED on Teensy 4.1

// Setup function runs once at startup
void setup()
{
    // Initialize the LED pin as an output
    pinMode(ledPin, OUTPUT);
}

// Loop function runs repeatedly after setup
void loop()
{
    // Turn the LED on
    digitalWrite(ledPin, HIGH);
    // Wait for 1 second (1000 milliseconds)
    delay(1000);
    // Turn the LED off
    digitalWrite(ledPin, LOW);
    // Wait for 1 second (1000 milliseconds)
    delay(1000);
}