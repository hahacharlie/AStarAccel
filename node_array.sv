`ifndef NODE_ARRAY_SV
`define NODE_ARRAY_SV

typedef struct packed {
    logic [31:0] f;               // Total cost (g + h)
  	logic [31:0] node_i;          // Current node's x-coordinate
  	logic [31:0] node_j;          // Current node's y-coordinate
} node_array_t;

`endif
