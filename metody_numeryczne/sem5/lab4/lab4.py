import numpy as np
import matplotlib.pyplot as plt

def S(V, rho, delta):
	S = 0
	for j in range(0, ny-2):
		for i in range(0, nx-2):
			S += (delta**2)*(1/2 * (V[j][i+1] - V[j][i])**2 + 1/2 * (V[j+1][i] - V[j][i])**2 - rho[j][i] * V[j][i])
	return S

def global_relaxation(vOld, rho, omega, ny ,nx, delta, epsilon):
	# j - kolumny, i - wiersze 
	vNew = [[0 for i in range(nx)] for j in range(ny)]
	for j in range(1, ny-1):
		for i in range(1, nx-1):
			# print(j,',',i,' ', end=' ')
			vNew[j][i] = 1/4 * (vOld[j][i+1] + vOld[j][i-1] + vOld[j+1][i] + vOld[j-1][i] + (delta**2) * rho[j][i]/epsilon)
	
	for j in range(0, ny - 1):
		vNew[j][0] = vNew[j][1]
		vNew[j][nx-1] = vNew[j][nx-2]

	# mix old and new potential
	for j in range(0, ny):
		for i in range(0, nx):
			vOld[j][i] = omega * vNew[j][i] + (1 - omega) * vOld[j][i]

	return vOld

def rho(x, y, xmax, ymax, sigma_x, sigma_y):
	rho1 = np.exp(-((x - 0.35 * xmax)**2 / (sigma_x**2) + (y - 0.5 * ymax)**2 / (sigma_y**2)))
	rho2 =-np.exp(-((x - 0.65 * xmax)**2 / (sigma_x**2) + (y - 0.5 * ymax)**2 / (sigma_y**2)))
	return rho1 + rho2

def solve(omega, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL):
	# Initialize potential and density arrays
	V = [[0 for i in range(nx)] for j in range(ny)]
	sArr = []
	it = []
	for i in range(0, nx):
		V[0][i] = V1
		V[ny-1][i] = V2

	# Initialize density array
	rho_array = [[0 for i in range(nx)] for j in range(ny)]

	# Fill density array
	for j in range(0, ny):
		for i in range(0, nx):
			rho_array[j][i] = rho(i, j, xmax, ymax, sigma_x, sigma_y)

	# Calculate S
	S_old = S(V, rho_array,delta)
	# Calculate potential
	V = global_relaxation(V, rho_array, omega, ny, nx, delta, epsilon)

	# Calculate S
	S_new = S(V, rho_array, delta)

	# Calculate difference
	difference = abs(S_old - S_new)

	# Iterate until difference is smaller than tolerance
	i = 1
	while difference > TOL:
		V = global_relaxation(V, rho_array, omega, ny, nx, delta, epsilon)
		S_new = S(V, rho_array,delta)
		difference = abs((S_old - S_new)/S_old)
		S_old = S_new
		i+=1
		sArr.append(S_new)
		it.append(i)
		print('Iteration: ', i, ' S: ', S_new)
		if i > 100:
			break
		
	return V, sArr, it 


if __name__ == '__main__':
	epsilon = 1.
	delta = 0.1
	nx = 150
	ny = 100
	V1 = 10.
	V2 = 0.
	xmax = delta * nx
	ymax = delta * ny
	sigma_x = 0.1 * xmax
	sigma_y = 0.1 * ymax
	omega_G = [0.6, 1.0]
	omega_L = [1.0, 1.4, 1.8, 1.9]
	TOL = 1e-8
	vArr1, sArr1, it1= solve(omega_G[0], nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)
	vArr2, sArr2, it2= solve(omega_G[0], nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)


	# plot S(it), axis x in log scale
	plt.figure()
	plt.xlabel('Iteration')
	plt.ylabel('S')
	plt.xscale('log')
	plt.plot(it1, sArr1, label='omega = 0.6')
	plt.plot(it2, sArr2, label='omega = 0.6')

	

	
	plt.savefig('S_global_relaxation.png')
	