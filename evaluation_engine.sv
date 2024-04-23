`include "node_mem.sv"
`include "sqrt_LUT.sv"

module evaluation_engine (
    input  logic        clk,
    input  logic        rst,
    input  logic        enable,  // Enable processing of a node
    input  logic [31:0] g,       // Cost from start to current node
    input  logic [15:0] x_curr,  // Current node x-coordinate
    input  logic [15:0] y_curr,  // Current node y-coordinate
    input  logic [15:0] x_goal,  // Goal node x-coordinate
    input  logic [15:0] y_goal,  // Goal node y-coordinate
    output logic [31:0] f,       // Output f value
    output logic        valid    // Valid signal when f is ready
);

  logic [31:0] delta_x, delta_y;
  logic [31:0] dist_sq;  // Distance squared
  logic [15:0] sqrt_dist;  // To store the result from SqrtLut
  sqrt_LUT sqrt_lut (
      .clk(clk),
      .dist_sq_index(dist_sq[9:0]),
      .sqrt_result(sqrt_dist)
  );

  // Calculate squared distance and handle square root calculation
  always_comb begin
    delta_x = x_curr - x_goal;
    delta_y = y_curr - y_goal;
    dist_sq = delta_x * delta_x + delta_y * delta_y;
  end

  // Compute f = g + h where h is sqrt_dist
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      f <= 0;
      valid <= 0;
    end else if (enable) begin
      f     <= g + sqrt_dist;  // h is taken from sqrt_dist
      valid <= 1;  // Signal that f is ready
    end else begin
      valid <= 0;
    end
  end

endmodule
