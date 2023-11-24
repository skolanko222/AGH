set term png
set palette defined (-10 "blue", 0 "white", 10 "red")
set size ratio -1
set xlabel "x"
set ylabel "y"
set pm3d map

set output "5a.png"
set title "nx=ny=50"
splot [0:5][0:5] "5a.txt" i 0 u 2:1:3

set output "5b.png"
set title "nx=ny=100"
splot [0:10][0:10] "5b.txt" i 0 u 2:1:3

set output "5c.png"
set title "nx=ny=200"
splot [0:20][0:20] "5c.txt" i 0 u 2:1:3

set output "6a.png"
set title "nx=ny=100, e1=1, e2=1"
splot [0:10][0:10][-0.8:0.8] "6a.txt" i 0 u 2:1:3

set output "6b.png"
set title "nx=ny=100, e1=1, e2=2"
splot [0:10][0:10][-0.8:0.8] "6b.txt" i 0 u 2:1:3

set output "6c.png"
set title "nx=ny=100, e1=1, e2=10"
splot [0:10][0:10][-0.8:0.8] "6c.txt" i 0 u 2:1:3