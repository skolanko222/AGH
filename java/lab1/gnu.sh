set terminal post enhanced colour solid font 20

set output "circle.eps"

set size square
unset key
set xlabel "x"
set ylabel "y"
set grid
plot  "circle.dat" pt 7 ps 0.5