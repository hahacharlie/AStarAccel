module sqrt_LUT (
    input logic clk,
    input logic [9:0] dist_sq_index,  // Input index for LUT
    output logic [15:0] sqrt_result  // Output square root result
);

  // ROM to store square root values, each 16 bits wide for 1024 entries, therefore 10 bits for index
  logic [15:0] sqrt_table[1023:0];

  // Initialize the LUT with precomputed square root values
  initial begin
    $readmemh("sqrt_values.hex", sqrt_table);  // Load precomputed values from a file
  end

  // Output the lookup result on every clock cycle
  always_ff @(posedge clk) begin
    sqrt_result <= sqrt_table[dist_sq_index];  // Lookup value
  end

endmodule
