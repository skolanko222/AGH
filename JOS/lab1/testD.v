module test_flipflop_d;

    reg clk;
    reg rst;
    reg [3:0] d;
    wire [3:0] q;

    // Instantiate the D flip-flop
    flipflop_d #(4) DUT (
        .clk(clk),
        .rst(rst),
        .d(d),
        .q(q)
    );

    // Clock generation
    always begin
        #5 clk = ~clk;
    end

    // Test procedure
    initial begin
        // Initialize signals
        clk = 0;
        rst = 0;
        d = 4'b0000;

        // Apply reset
        rst = 1;
        #10 rst = 0;

        // Apply data inputs according to the given timeline
        #1 d = 4'b1111; // High after 1ns
        #9 d = 4'b0000; // Low 3ns after the next falling edge of the clock
        #6 d = 4'b1111; // High 1ns after the next falling edge of the clock
        #20 d = 4'b0000; // Low after two more falling edges of the clock and 6ns
        #19 d = 4'b1111; // High after three more falling edges of the clock and 4ns

        // End of test after 10 rising edges of the clock
        #10 $finish;
    end

endmodule