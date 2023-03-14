import sys
import math

if len(sys.argv) !=5:
	sys.exit()

a = float(sys.argv[1])
b = float(sys.argv[2])
c = float(sys.argv[3])
eps = float(sys.argv[4])

if(d:=b**2-4*a*c)>eps:
	x1= (-b-math.sqrt(d))/(2*a)
	x2= (-b-math.sqrt(d))/(2*a)
	print(f'{x1},{x1}')
else math.fabs(d) <= eps:
	