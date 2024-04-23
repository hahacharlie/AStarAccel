#include "Vopen_list_array.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);  // Initialize Verilator's variables
    Vopen_list_array* dut = new Vopen_list_array;  // Create instance of the module

    dut->rst = 1;  // Assert reset
    dut->clk = 0;  // Start with clk at 0
    dut->eval();
    dut->rst = 0;  // Deassert reset
    dut->eval();

    bool pass = true;

    // Example simulation loop
    for (int time = 0; time < 20; time++) {
        if ((time % 2) == 0) {  // Toggle clock
            dut->clk = !dut->clk;
        }

        if (time == 1) {
            dut->rst = 1;  // Assert reset
        }

        if (time == 3) {
            dut->rst = 0;  // Deassert reset
        }

        // Insert and pop simulation code, manipulate insert_enable, pop_enable, and node_in
        if (time == 5) {
            dut->insert_enable = 0xFF;  // Example: Enable insert on all queues
            // Assume node_t is a simple integer for example purposes
            for (int i = 0; i < 8; i++) {
                dut->node_in[i] = i;  // Assign values to node inputs
            }
        }

        if (time == 10) {
            dut->pop_enable = 0xFF;  // Example: Enable pop on all queues
        }

        dut->eval();

        // Check outputs and validate
        if (time > 10) {
            for (int i = 0; i < 8; i++) {
                if (dut->node_out_valid[i]) {
                    std::cout << "Queue " << i << " Output: " << dut->node_out[i] << std::endl;
                }
            }
        }
    }

    // Finish simulation and cleanup
    dut->final();
    delete dut;
    return 0;
}
