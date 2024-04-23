`ifndef NODE_MEM_SV
`define NODE_MEM_SV

typedef struct packed {
    logic [31:0] g;               // Cost from start to current node
    logic [31:0] h;               // Heuristic estimate from current node to goal
    logic [31:0] f;               // Total cost (g + h)
    logic in_open_list;           // Flag to check if in priority queue
  	logic is_obstacle;            // Flag to check if it's an obstacle
    logic [31:0] parent_i;        // Parent node's x-coordinate
  	logic [31:0] parent_j;        // Parent node's y-coordinate
} node_mem_t;

`endif
