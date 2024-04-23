`include "node_mem.sv"
`include "node_array.sv"
`include "comparison_engine.sv"

module nodes_management(
    input logic clk,
    input logic rst,
    input node_array_t new_nodes[16],    // Adjusted type to node_array_t
    input logic [15:0] new_nodes_valid,  // Bitmask indicating which new nodes are valid
    output node_array_t node_to_expand,  // Node selected for expansion
    output logic node_to_expand_valid    // Indicates if the node_to_expand is valid
);

    // Local parameters
    parameter int MAX_NODES = 1024; // Example size of lists

    // Memory for OPEN and CLOSED lists (simplified implementation)
    node_array_t open_list[MAX_NODES]; // Adjusted type to node_array_t
    logic [MAX_NODES-1:0] open_list_valid;

    // Instantiate the comparison engine
    comparison_engine comp_engine(
        .clk(clk),
        .rst(rst),
        .nodes(new_nodes),
        .min_node(node_to_expand)
    );

    integer i;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // Initialize lists
            for (i = 0; i < MAX_NODES; i++) begin
                open_list_valid[i] = 0;
            end
            node_to_expand_valid = 0;
        end else begin
            // Process new nodes
            for (i = 0; i < 16; i++) begin
                if (new_nodes_valid[i]) begin
                    // Assume new nodes are directly added to OPEN list for simplicity
                    int idx = find_empty_slot(open_list_valid);
                    if (idx != -1) begin
                        open_list[idx] = new_nodes[i];
                        open_list_valid[idx] = 1;
                    end
                end
            end

            // Select the best node to expand
            node_to_expand_valid = 1; // Assume the comparison engine always provides a valid node
        end
    end

    // Simple function to find an empty slot in a list
    function int find_empty_slot(logic [MAX_NODES-1:0] valid_bits);
        find_empty_slot = -1;
        for (int j = 0; j < MAX_NODES; j++) begin
            if (!valid_bits[j]) begin
                find_empty_slot = j;
                break;
            end
        end
    endfunction

endmodule
