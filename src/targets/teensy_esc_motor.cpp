#include <Servo.h>
#include <Arduino.h>

Servo esc; // create servo object to control the ESC

int write_val = 1500;
void setup()
{
    esc.attach(22, 1000, 2000); // Attach the ESC to pin 9
    esc.write(write_val);
    delay(10000); // Wait for 3 seconds to allow the ESC to initialize
}

void loop()
{
    if (write_val > 1800)
    {
        write_val = 1200;
    }

    write_val = write_val + 5;
    esc.writeMicroseconds(write_val);
    delay(20);

    // // Example to control the motor
    // // This will gradually increase the throttle from 0 to maximum
    // for (int throttle = 1000; throttle <= 1400; throttle += 10)
    // {
    //     esc.writeMicroseconds(throttle); // Send throttle signal
    //     delay(20);                       // Small delay to allow the motor to respond
    // }

    // // Hold the maximum throttle for a while
    // delay(2000);

    // // Gradually decrease the throttle back to 0
    // for (int throttle = 1400; throttle >= 1000; throttle -= 10)
    // {
    //     esc.writeMicroseconds(throttle); // Send throttle signal
    //     delay(20);                       // Small delay to allow the motor to respond
    // }

    // // Hold the zero throttle for a while
    // delay(2000);
}
