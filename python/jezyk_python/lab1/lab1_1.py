a = float(input("Podaj a:"))
b = float(input("Podaj b:"))
c = float(input("Podaj c:"))

ret = []

delta = b**2 - 4*a*c
if delta>1e-6:
	ret.append((-b + pow(delta,.5))/(2*a))
	ret.append((-b - pow(delta,.5))/(2*a))
elif abs(delta) <= 1e-6:
	ret.append(-b/(2*a))
else:
	ret.append((-b + pow(delta, 0.5))/(2*a))
	ret.append((-b - pow(delta, 0.5))/(2*a))

	
a,s,f = 23,23,23

print(ret)