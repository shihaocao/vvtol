#ifndef NATIVE
#include <Arduino.h>
#endif

#include <state_field_registry.hpp>
#include <main_loop.hpp>
#include <atomic>
#include <csignal>
#include <globals.hpp>

StateFieldRegistry sfr = StateFieldRegistry{0};
MainLoop main_loop = MainLoop(sfr);

std::atomic<bool> keepRunning(true);

void signalHandler(int signum) {
    log() << "Interrupt signal (" << signum << ") received.\n";
    keepRunning = false;
}

void setup() {
  // put your setup code here, to run once:
  main_loop.setup();
  std::signal(SIGINT, signalHandler);

}

void loop() {
  log() << "MAIN START\n";

  // put your main code here, to run repeatedly:
  main_loop.execute();

  // explicilty dump the logs instead of doing it in a destructor
  log() << global_stats.to_string();\
  log() << "MAIN DONE\n";
  // log().flush();
}

#ifdef NATIVE
int main() {
  setup();
  while(keepRunning) {
    loop();
  }
  
  // explicilty dump the logs instead of doing it in a destructor
  log() << global_stats.to_string();\
  log() << "MAIN DONE\n";
  log().flush();
}
#endif