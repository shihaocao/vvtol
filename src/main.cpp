#ifndef NATIVE
#include <Arduino.h>
#endif

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

#ifdef NATIVE
int main() {
  setup();
  while(true) {
    loop();
  }
}
#endif