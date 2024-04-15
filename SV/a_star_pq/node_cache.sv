`include "node_types.sv"

module node_cache #(
    parameter int CACHE_SIZE = 1024, // Size of the cache
    parameter int NUM_PORTS = 8      // Number of cache ports
)(
    input logic clk,
    input logic rst,
    input logic [NUM_PORTS-1:0][log2(CACHE_SIZE)-1:0] read_addresses, // Read addresses for each port
    input logic [NUM_PORTS-1:0] read_enable,                          // Enable read per port
    input logic [log2(CACHE_SIZE)-1:0] write_address,                 // Write address
    input node_t write_data,                                          // Data to write
    input logic write_enable,                                         // Enable writing
    output logic [NUM_PORTS-1:0] read_valid,                          // Data valid output signals
    output node_t [NUM_PORTS-1:0] read_data                           // Data outputs for each port
);

    // Local memory to store nodes
    node_t memory[CACHE_SIZE];

    // Read operation
    always_ff @(posedge clk) begin
        for (int i = 0; i < NUM_PORTS; i++) begin
            if (read_enable[i]) begin
                read_data[i] <= memory[read_addresses[i]];
                read_valid[i] <= 1'b1;
            end else begin
                read_valid[i] <= 1'b0;
            end
        end

        // Write operation
        if (write_enable) begin
            memory[write_address] <= write_data;
        end
    end

    // Handle reset
    always_ff @(posedge rst) begin
        if (rst) begin
            // Initialize memory or perform necessary reset actions
            for (int i = 0; i < CACHE_SIZE; i++) begin
                memory[i] <= '0;
            end
        end
    end

endmodule