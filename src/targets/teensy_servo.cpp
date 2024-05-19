#include <Arduino.h>
#include <Servo.h>

// Define the pin for the servo
const int servoPin = 28; // Pin number for the servo on Teensy 4.1

// Create a Servo object
Servo myServo;

void setup()
{
    // Attach the servo object to the servo pin
    myServo.attach(servoPin);
}

void loop()
{
    // Sweep the servo from 0 to 180 degrees
    for (int pos = 0; pos <= 180; pos++)
    {
        myServo.write(pos); // Set the servo to 'pos' degrees
        delay(15);          // Wait for 15 milliseconds
    }

    // Sweep the servo from 180 to 0 degrees
    for (int pos = 180; pos >= 0; pos--)
    {
        myServo.write(pos); // Set the servo to 'pos' degrees
        delay(15);          // Wait for 15 milliseconds
    }
}
