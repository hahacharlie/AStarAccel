`ifndef NODE_TYPES_SV
`define NODE_TYPES_SV

typedef struct packed {
    int g;              // Cost from start to current node
    int h;              // Heuristic estimate from current node to goal
    int f;              // Total cost (g + h)
    logic in_queue;     // Flag to check if in priority queue
  	logic is_obstacle;  // Flag to check if it's an obstacle
  	short node_i;       // Current node's x-coordinate
  	short node_j;       // Current node's y-coordinate
    short parent_i;     // Parent node's x-coordinate
  	short parent_j;     // Parent node's y-coordinate
} node_t;

`endif
