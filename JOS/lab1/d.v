module flipflop_d #(parameter n=4) (
    input wire clk,
    input wire rst,
    input wire [n-1:0] d,
    output reg [n-1:0] q
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            q <= 'b0;
        else
            q <= d;
    end
endmodule