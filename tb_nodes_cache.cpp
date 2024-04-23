#include "Vnodes_cache.h"
#include "verilated.h"

int main(int argc, char **argv, char **env) {
  Verilated::commandArgs(argc, argv); // Setup Verilator arguments

  // Create an instance of our module under test
  Vnodes_cache *top = new Vnodes_cache;

  // Simulate for 100 clock cycles
  for (int i = 0; i < 100; i++) {
    // Toggle clock input
    top->clk = !top->clk;
    top->eval(); // Evaluate model
  }

  top->final(); // Done simulating
  delete top;   // Destroy instance

  return 0;
}
