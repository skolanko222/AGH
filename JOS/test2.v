library IEEE;
use IEEE.std_logic_1164.all;
entity flipflop_d is
port (clk, rst, d : in std_logic;
q : out std_logic);
end entity;
architecture proj of flipflop_d is
begin
process(clk, rst)
begin
if rst = ’1’ then
q <= ’0’;
elsif rising_edge(clk) then
q <= d;
end if;
end proces;
end architecture;