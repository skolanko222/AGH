// Rejestr n-bitowy
module flipflop_d #(parameter n=4)
(input clk, rst, input [n-1:0] d, output reg [n-1:0] q);
always @(posedge clk, posedge rst)
if(rst)
q <= {n{1’b0}};
else
q <= d;
endmodule
