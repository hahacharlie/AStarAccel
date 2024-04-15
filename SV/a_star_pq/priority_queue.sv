`include "node_types.sv"

module priority_queue #(
    parameter int QUEUE_SIZE = 256
)(
    input logic clk,
    input logic rst,
    input logic insert_enable,
    input logic pop_enable,
    input node_t node_in,
    output logic empty,
    output logic full,
    output node_t node_out
);

    // Internal variables
    node_t queue[QUEUE_SIZE];
    int num_elements = 0;  // Track the number of elements in the queue

    // Initialize the queue to be empty at reset
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            num_elements <= 0;
        end else begin
            if (insert_enable && !full) begin
                // Insert new node in the sorted order
                int i;
                for (i = num_elements; i > 0; i--) begin
                    if (queue[i-1].f > node_in.f) begin
                        queue[i] = queue[i-1];
                    end else begin
                        break;
                    end
                end
                queue[i] = node_in;
                num_elements <= num_elements + 1;
            end

            if (pop_enable && !empty) begin
                // Pop the node with the smallest f
                node_out <= queue[0];
                for (int j = 0; j < num_elements - 1; j++) begin
                    queue[j] = queue[j+1];
                end
                num_elements <= num_elements - 1;
            end
        end
    end

    // Determine if the queue is empty or full
    assign empty = (num_elements == 0);
    assign full = (num_elements == QUEUE_SIZE);

endmodule
