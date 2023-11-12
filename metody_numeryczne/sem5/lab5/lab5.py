# Przyjmujemy wartości parametrów: ∆ = 0.2, nx = 128, ny = 128, xmax = ∆ · nx, ymax = ∆ · ny,
# T OL = 10−8 oraz warunki brzegowe Dirichleta:
# 2. Rozwiązać równanie Poissona z zadanymi WB metodą wielosiatkową dla k = 16, 8, 4, 2, 1. Dla
# każdego k po spełnieniu warunku stopu sporządzić mapę potencjału (5 map). (60 pkt) Dla
# każdego k zapisać do pliku wartości całki funkcjonalnej w funkcji numeru iteracji. Sporządzić
# wykres zmian S(k)(it) dla wszystkich k na jednym rysunku. (40 pkt)

import numpy as np
import math
import matplotlib.pyplot as plt

delta = 0.2
nx = 128
ny = 128
xmax = delta * nx
ymax = delta * ny
TOL = 10**(-8)
kArr = [16, 8, 4, 2, 1]

def Vb1(y):
	return math.sin(math.pi*y/ymax)
def Vb2(x):
	return -math.sin(2*math.pi*x/xmax)
def Vb3(y):
	return math.sin(math.pi*y/ymax)
def Vb4(x):
	return math.sin(2*math.pi*x/xmax)
def fill_boundary_conditions(V):
	for i in range(0, nx):
		V[0][i] = Vb1(i*delta)
		V[ny-1][i] = Vb3(i*delta)
	for j in range(0, ny):
		V[j][ny-1] = Vb2(j*delta)
		V[j][0] = Vb4(j*delta)

def relaxate(V,k):
	for i in range(k,nx-k,k):
		for j in range(k,ny-k,k):
			V[i][j] = 0.25*(V[i+k][j]+V[i-k][j]+V[i][j+k]+V[i][j-k])
def S(V,k):
	sum = 0
	divider = 1/(2*k*delta)
	constFrac = ((k*delta)**2)/2

	for i in range(0,nx-k,k):
		for j in range(0,ny-k,k):
			# print(i,j)

			firstFrac = (V[i+k][j]-V[i][j])/divider
			secondFrac = (V[i+k][j+k]-V[i][j+k])/divider
			firstPow = (firstFrac + secondFrac)**2

			firstFrac = (V[i][j+k]-V[i][j])/divider
			secondFrac = (V[i+k][j+k]-V[i+k][j])/divider
			secondPow = (firstFrac + secondFrac)**2

			sum += constFrac*(firstPow + secondPow)
	return sum

def dens_mesh(V,k):
	k2 = k//2
	for i in range(0,nx-k,k):
		for j in range(0,ny-k,k):
			# print(i,j,k)
			V[i+k2][j+k2] = 0.25*(V[i][j]+V[i+k][j]+V[i][j+k]+V[i+k][j+k])
			V[i+k][j+k2] = 0.5*(V[i+k][j]+V[i+k][j+k])
			V[i+k2][j+k] = 0.5*(V[i][j+k]+V[i+k][j+k])
			V[i+k2][j] = 0.5*(V[i][j]+V[i+k][j])
			V[i][j+k2] = 0.5*(V[i][j]+V[i][j+k])


if __name__ == '__main__':
	V = np.zeros((nx, ny))
	fill_boundary_conditions(V)
	# np.savetxt('V1.txt', V) # krańcowe warunki brzegowe inaczej
	it = 0
	sPrev = 0
	for k in kArr:
		while True:
			it += 1
			relaxate(V,k)
			s = S(V,k)
			temp = (s-sPrev)/sPrev
			if abs(temp) < TOL:
				break
			sPrev = s
			# np.savetxt('V'+str(k)+'.txt', V)
			print('it =',it,'k =',k,'var =',temp)
		Vtemp = np.zeros((k, k))
		# for i in range(k, k):
		# 	for j in range(0, k):
		# 		Vtemp[i*]	
		plt.imshow(np.rot90(V), cmap='hot', interpolation='bilinear')
		plt.savefig('V'+str(k)+'.png')
		if(k != 1):
			dens_mesh(V,k)
		it = 0
	# plot heatmap of V

