`include "node_mem.sv"

module nodes_cache #(
    parameter logic [31:0] ADDR_WIDTH    = 10,                       // Adjust based on actual address size
    parameter logic [31:0] INDEX_SIZE    = 5,                        // 32 sets if index size is 5 bits
    parameter logic [31:0] TAG_WIDTH     = ADDR_WIDTH - INDEX_SIZE,
    parameter logic [31:0] NUM_SETS      = 1 << INDEX_SIZE,          // Number of sets derived from index size
    parameter logic [31:0] NUM_WAYS      = 2,                        // 2-way set associative
    parameter logic [31:0] NUM_PORTS     = 8                         // 8 ports for simultaneous access
)(
    input   logic                        clk,                        // System clock
    input   logic                        rst,                        // Reset
    input   logic [NUM_PORTS-1:0]        valid,                      // Valid inputs for each port
    input   logic [NUM_PORTS-1:0]        write,                      // Write enable for each port
    input   logic [ADDR_WIDTH-1:0]       address[NUM_PORTS],         // Address for each port
    input   node_mem_t                   data_in[NUM_PORTS],         // Data input for each port
    output  logic [NUM_PORTS-1:0]        hit,                        // Hit flag for each port
    output  node_mem_t                   data_out[NUM_PORTS]         // Data output for each port
);

typedef struct packed {
    logic valid;
    logic lru; // Flag to indicate LRU
    logic [TAG_WIDTH-1:0] tag;
    node_mem_t data;
} cache_line;

// 2-way set associative cache structure: NUM_SETS x NUM_WAYS
cache_line node_cache[NUM_SETS][NUM_WAYS];

// Address breakdown
logic [INDEX_SIZE-1:0] index[NUM_PORTS];
logic [TAG_WIDTH-1:0] tag[NUM_PORTS];

always_comb begin
    for (int i = 0; i < NUM_PORTS; i++) begin
        index[i] = address[i][INDEX_SIZE-1:0];
        tag[i] = address[i][ADDR_WIDTH-1:INDEX_SIZE];
    end
end

// Cache operation
always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        for (int i = 0; i < NUM_SETS; i++) begin
            for (int j = 0; j < NUM_WAYS; j++) begin
                node_cache[i][j].valid <= 0;
                node_cache[i][j].lru <= 0;
            end 
        end
    end else begin
        for (int p = 0; p < NUM_PORTS; p++) begin
            hit[p] <= 0;
            data_out[p] <= 'x;  // Default invalid data
            if (valid[p]) begin
                logic [INDEX_SIZE-1:0] set_idx;
                set_idx <= index[p];
                // Check for hit and update LRU
                for (int way = 0; way < NUM_WAYS; way++) begin
                    if (node_cache[set_idx][way].valid && node_cache[set_idx][way].tag == tag[p]) begin
                        hit[p] <= 1;
                        data_out[p] <= node_cache[set_idx][way].data;
                        // Update LRU
                        node_cache[set_idx][way].lru <= 1;
                        node_cache[set_idx][1-way].lru <= 0;
                    end
                end 
                // Handle miss and potential write
                if (!hit[p] && write[p]) begin
                    // Find LRU way for replacement
                    logic lru_way; 
                    lru_way <= node_cache[set_idx][0].lru ? 1 : 0;
                    node_cache[set_idx][lru_way].valid <= 1;
                    node_cache[set_idx][lru_way].tag <= tag[p];
                    node_cache[set_idx][lru_way].data <= data_in[p];
                    // Update LRU
                    node_cache[set_idx][lru_way].lru <= 1;
                    node_cache[set_idx][1-lru_way].lru <= 0;
                end 
            end 
        end 
    end 
end 

endmodule 
