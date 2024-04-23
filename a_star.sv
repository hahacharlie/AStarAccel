`include "node.sv"
`include "open_list_array.sv"
`include "nodes_cache.sv"

module a_star_accelerator #(
    parameter int GRID_SIZE = 256,  // Assuming a 256x256 grid for simplicity
    parameter int CACHE_SIZE = 1024 // Cache size
)(
    input logic clk,
    input logic rst,
    input logic start,             // Start signal for pathfinding
    input node_t start_node,       // Start node with coordinates and other information
    input node_t goal_node,        // Goal node with coordinates and other information
    output logic done,             // Done signal indicating completion
    output logic path_found,       // Indicates if a path has been found
    output node_t path[GRID_SIZE]  // Array to store the path found
);

// Define internal signals for cache operation
logic [7:0][log2(CACHE_SIZE)-1:0] read_addresses;
logic [7:0] read_enable;
logic [log2(CACHE_SIZE)-1:0] write_address;
node_t write_data;
logic write_enable;
logic [7:0] read_valid;
node_t [7:0] read_data;
node_t current_node;
logic pq_empty, pq_full;

// Start and goal coordinates
short start_i, start_j, goal_i, goal_j;

// Path storage
node_t [GRID_SIZE] path;
int path_index;

// Instantiate priority queue and node cache
priority_queue pq(
    .clk(clk),
    .rst(rst),
    .node_in(current_node),
    .insert_enable(insert_enable),
    .pop_enable(pop_enable),
    .node_out(current_node),
    .empty(pq_empty),
    .full(pq_full)
);

// Instantiate the node cache
node_cache #(
    .CACHE_SIZE(CACHE_SIZE),
    .NUM_PORTS(8)
) cache (
    .clk(clk),
    .rst(rst),
    .read_addresses(read_addresses),
    .read_enable(read_enable),
    .write_address(write_address),
    .write_data(write_data),
    .write_enable(write_enable),
    .read_valid(read_valid),
    .read_data(read_data)
);

// Definitions of states
typedef enum int {IDLE, INIT, PROCESSING, CHECK_GOAL, BACKTRACK, DONE} state_t;
state_t state, next_state;

// Function to estimate the cost from a node to the goal using Manhattan distance
function int heuristic_estimate(short i1, short j1, short i2, short j2);
    return (abs(i1 - i2) + abs(j1 - j2)); 
endfunction

// Function to calculate memory address from coordinates
function int calculate_address(short i, short j);
    return (i * GRID_SIZE + j); // Assuming row-major order in a GRID_SIZE x GRID_SIZE grid
endfunction

// Function to calculate the address of the current node
function int current_node_address();
    // Assuming the current node's coordinates are maintained globally
    return calculate_address(current_node.node_i, current_node.node_j);
endfunction

// Function to fetch the parent node from the cache
function node_t fetch_parent(node_t node);
    int parent_address = calculate_address(node.parent_i, node.parent_j);
    read_addresses[0] = parent_address; // Set address to read from cache
    read_enable[0] = 1'b1;              // Enable read

    // Assume synchronous read for simplicity, in practice handle read enable and timing
    // Here we return a dummy value as actual implementation would require clock cycle to fetch
    return node_cache[parent_address]; // Direct access for illustration; real implementation needs proper synchronization
endfunction

// State transition and operations logic
always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        state <= IDLE;
        path_index <= 0;
    end else begin
        state <= next_state;
    end
end

// State logic and pathfinding operations
always_comb begin
    next_state = state;
    case (state)
        IDLE: begin
            if (start) begin
                next_state = INIT;
            end
        end
        INIT: begin
            // Initialize the start node and place it in the priority queue
            node_t start_node;
            start_node.node_i = start_i;
            start_node.node_j = start_j;
            start_node.g = 0; // Cost from start to start is zero
            start_node.h = heuristic_estimate(start_i, start_j, goal_i, goal_j);
            start_node.f = start_node.g + start_node.h;
            write_address = calculate_address(start_i, start_j); // Function to map coordinates to memory addresses
            write_data = start_node;
            write_enable = 1'b1;
            next_state = PROCESSING;
        end
        PROCESSING: begin
            if (!pq_empty) begin
                pop_enable = 1'b1; // Pop the node with the lowest f from the priority queue
                read_addresses[0] = current_node_address(); // Function to calculate address of the current node
                read_enable[0] = 1'b1;
                next_state = CHECK_GOAL;
            end else begin
                next_state = DONE;
            end
        end
        CHECK_GOAL: begin
            if (current_node.node_i == goal_i && current_node.node_j == goal_j) begin
                next_state = BACKTRACK;
            end else {
                next_state = PROCESSING; // Expand node, find successors, push to queue
            }
        end
        BACKTRACK: begin
            if (current_node.parent_i != -1 && current_node.parent_j != -1) { // Assuming -1 as invalid parent indicator
                path[path_index++] = current_node;
                current_node = fetch_parent(current_node); // Fetch the parent node
            } else {
                next_state = DONE;
            }
        end
        DONE: begin
            done = 1'b1;
            path_found = (path_index > 0);
        end
    endcase
end

endmodule
