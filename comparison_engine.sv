`include "node_array.sv"

module comparison_engine(
    input logic clk,
    input logic rst,
    input node_array_t nodes[16],  // Array of 16 node inputs
    output node_array_t min_node   // Output node with minimum f value
);

    logic [3:0] min_index;  // To store the index of the node with minimum f

    always_comb begin
        min_node = nodes[0];  // Initialize min_node with the first node
        min_index = 0;

        for (int i = 1; i < 16; i++) begin
            if (nodes[i].f < min_node.f) begin
                min_node = nodes[i];  // Update min_node if a smaller f is found
                min_index = i;
            end 
        end
    end

endmodule
