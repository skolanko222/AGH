module flipflop_d (input clk, rst, d, output reg q); // d is the input, q is the output, reg -which can hold a value until changed by a subsequent assignment.
	always @(posedge clk, posedge rst) // posedge - positive edge of the clock
	if(rst)
		q <= 1’b0;
	else
		q <= d;
endmodule

