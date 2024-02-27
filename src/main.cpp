#ifndef NATIVE
#include <Arduino.h>
#endif

#include <main_loop.hpp>

StateFieldRegistry sfr;
MainLoop main_loop(sfr);

void setup() {
  // put your setup code here, to run once:
  main_loop.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  main_loop.execute();
}

#ifdef NATIVE
int main() {
  setup();
  while(true) {
    loop();
  }
}
#endif