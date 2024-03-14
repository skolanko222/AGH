library IEEE;
use IEEE.std_logic_1164.all;
entity flipflop_d is
	generic (n : natural := 4);
	port(clk, rst : in std_logic;
		d : in std_logic_vector (n-1 downto 0);
		q : out std_logic_vector (n-1 downto 0));
end entity;

architecture proj of flipflop_d is

begin
process(clk, rst) begin
	if rst = ’1’ then
		q <= (others => ’0’);
	elsif rising_edge(clk) then
		q <= d;
	end if;
end proces;
end architecture;
