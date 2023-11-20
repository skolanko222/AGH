import numpy as np
import matplotlib.pyplot as plt
def S(V, rho,delta):
	S = 0
	for i in range(0, nx-1):
		for j in range(0, ny-1):
			S += (delta**2) * (0.5*(((V[i+1,j]-V[i,j])/delta)**2) + 0.5*(((V[i,j+1]-V[i,j])/delta)**2) - (rho[i,j]*V[i,j]))
	return S

def global_relaxation(vOld, rho, omega, ny, nx, delta, epsilon, V1, V2):
	vNew = np.zeros((nx, ny))
	for i in range(0, nx):
		vNew[i][0] = V1
		vNew[i][ny-1] = V2

	for i in range(1, nx-1):
		for j in range(1, ny-1):
			vNew[i][j] = 0.25 * (vOld[i+1][j] + vOld[i-1][j] + vOld[i][j+1] + vOld[i][j-1] + delta**2 * rho[i][j]/epsilon)
	for j in range(0, ny - 1):
		vNew[0][j] = vNew[1][j]
		vNew[nx-1][j] = vNew[nx-1][j]

	# mix old and new potential
	vOld = (1 - omega) * vOld + omega * vNew
	return vOld
def local_relaxation(vOld, rho, omega, ny, nx, delta, epsilon, V1, V2):
	for i in range(1, nx-1):
		for j in range(1, ny-1):
			vOld[i][j] = (1 - omega) * vOld[i][j] + (omega/4) * (vOld[i+1][j] + vOld[i-1][j] + vOld[i][j+1] + vOld[i][j-1] + (delta**2/epsilon) * rho[i][j])
	for j in range(0, ny - 1):
		vOld[0][j] = vOld[1][j]
		vOld[nx][j] = vOld[nx-1][j]
	return vOld

def rho(x, y, xmax, ymax, sigma_x, sigma_y):
	rho1 = np.exp(-((x - 0.35 * xmax)**2 / (sigma_x**2) + (y - 0.5 * ymax)**2 / (sigma_y**2)))
	rho2 =-np.exp(-((x - 0.65 * xmax)**2 / (sigma_x**2) + (y - 0.5 * ymax)**2 / (sigma_y**2)))
	return rho1 + rho2

def solve(omega,method, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL):
	# Initialize potential and density arrays
	rho_array = np.zeros((nx, ny))
	V = np.zeros((nx, ny))
	sArr = []
	it = []
	
	# Fill boundary conditions
	for i in range(0, nx):
		V[i][0] = V1
		V[i][ny-1] = V2

	# Fill density array
	for j in range(0, ny):
		for i in range(0, nx):
			rho_array[i][j] = rho(i, j, xmax, ymax, sigma_x, sigma_y)
	i = 1
	S_old = S(V, rho_array, delta)
	difference = 1
	print(f'omega: {omega}')
	while difference > TOL:
		V = method(V, rho_array, omega, ny, nx, delta, epsilon, V1, V2)
		S_new = S(V, rho_array,delta)
		difference = abs((S_old - S_new)/S_old)
		i+=1
		S_old = S_new
		sArr.append(S_old)
		it.append(i)
		print('Iteration: ', i, ' S: ', S_old)
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
	vArr1, sArr1, it1= solve(omega_G[0],global_relaxation, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)
	vArr2, sArr2, it2= solve(omega_G[1],global_relaxation, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)

	vArr3, sArr3, it3= solve(omega_L[0],global_relaxation, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)
	vArr4, sArr4, it4= solve(omega_L[1],global_relaxation, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)
	vArr5, sArr5, it5= solve(omega_L[2],global_relaxation, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)
	vArr6, sArr6, it6= solve(omega_L[3],global_relaxation, nx, ny, xmax, ymax, sigma_x, sigma_y, delta, epsilon, V1, V2, TOL)

	# plot potential - global relaxation
	plt.figure()
	plt.xlabel('x')
	plt.ylabel('y')
	plt.imshow(vArr1, cmap='jet')
	plt.colorbar()
	plt.savefig('potential_global_relaxation.png')
	# plot potential - local relaxation
	plt.figure()
	plt.xlabel('x')
	plt.ylabel('y')
	plt.imshow(vArr4, cmap='jet')
	plt.colorbar()
	plt.savefig('potential_local_relaxation.png')
	# plot S(it), axis x in log scale
	plt.figure()
	plt.xlabel('Iteration')
	plt.ylabel('S')
	plt.xscale('log')
	plt.plot(it1, sArr1, label='omega = 0.6')
	plt.plot(it2, sArr2, label='omega = 1')
	plt.legend()
	plt.savefig('global_relaxation.png')
	# ss
	plt.figure()
	plt.xlabel('Iteration')
	plt.ylabel('S')
	plt.xscale('log')
	plt.plot(it3[1:], sArr3[1:], label='omega = 1')
	plt.plot(it4[1:], sArr4[1:], label='omega = 1.4')
	plt.plot(it5[1:], sArr5[1:], label='omega = 1.8')
	plt.plot(it6[1:], sArr6[1:], label='omega = 1.8')

	plt.legend()
	plt.savefig('local_relaxation.png')
	