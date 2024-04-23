`include "node_array.sv"

module open_list_array #(
    parameter int QUEUE_SIZE = 256,  // Size of each queue
    parameter int NUM_QUEUES = 8     // Number of parallel queues
)(
    input logic clk,
    input logic rst,
    input logic [NUM_QUEUES-1:0] insert_enable,     // Signal to insert node
    input logic [NUM_QUEUES-1:0] pop_enable,        // Signal to pop the top node
    input node_array_t [NUM_QUEUES-1:0] node_in,    // Nodes entering the queue
    output logic [NUM_QUEUES-1:0] node_out_valid,   // Valid signal for output nodes
    output node_array_t [NUM_QUEUES-1:0] node_out   // Nodes output from the queue
);

typedef struct packed {
    logic valid;
    node_array_t node;
} queue_node_t;

// Arrays for input and output buffers
queue_node_t IB [NUM_QUEUES][QUEUE_SIZE];
queue_node_t OB [NUM_QUEUES][QUEUE_SIZE];

always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        // Reset logic for IB and OB
        for (int i = 0; i < NUM_QUEUES; i++) begin 
            for (int j = 0; j < QUEUE_SIZE; j++) begin 
                IB[i][j].valid = 0;
                OB[i][j].valid = 0;
            end 
        end
    end else begin
        for (int i = 0; i < NUM_QUEUES; i++) begin 
            if (insert_enable[i]) begin
                // Insert node into IB and perform sorting into OB
                IB[i][0].node = node_in[i];
                IB[i][0].valid = 1;
                for (int j = 0; j < QUEUE_SIZE - 1; j++) begin 
                    if (OB[i][j].valid && OB[i][j].node.f > IB[i][0].node.f) begin 
                        // Bubble sort: Swap OB and IB nodes if OB node's f is greater
                        node_array_t temp = OB[i][j].node;
                        OB[i][j].node = IB[i][0].node;
                        IB[i][0].node = temp;
                    end 
                end 
            end 
            if (pop_enable[i] && OB[i][0].valid) begin 
                // Pop the head node from OB
                node_out[i] = OB[i][0].node;
                node_out_valid[i] = 1;
                // Shift all nodes in OB
                for (int j = 0; j < QUEUE_SIZE - 1; j++) begin 
                    OB[i][j] = OB[i][j+1];
                end 
                OB[i][QUEUE_SIZE-1].valid = 0;  // Clear the last element
            end 
        end 
    end
end

endmodule
