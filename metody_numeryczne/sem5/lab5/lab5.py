import numpy as np
import math
import matplotlib.pyplot as plt
from matplotlib import colormaps
import time

delta = 0.2
nx = 128
ny = 128
xmax = delta * nx
ymax = delta * ny
TOL = 10**(-8)
kArr = [16,8,4,2,1]

def Vb1(y):
	return math.sin(math.pi*(y/ymax))
def Vb2(x):
	return -math.sin(2*math.pi*(x/xmax))
def Vb3(y):
	return math.sin(math.pi*(y/ymax))
def Vb4(x):
	return math.sin(2*math.pi*(x/xmax))
def fill_boundary_conditions(V):
	for i in range(0, nx):
		V[0][i] = Vb1(i*delta)
		V[ny-1][i] = Vb3(i*delta)
	for j in range(0, ny):
		V[j][ny-1] = Vb2(j*delta)
		V[j][0] = Vb4(j*delta)

def relaxate(V,k):
	if k == 1:
		for i in range(k,nx-k,k):
			for j in range(k,ny-k,k):
				V[i][j] = 0.25*(V[i-k][j]+V[i+k][j]+V[i][j-k]+V[i][j+k])
	else:
		for i in range(k,nx,k):
			for j in range(k,ny,k):
				try:
					V[i][j] = 0.25*(V[i-k][j]+V[i+k][j]+V[i][j-k]+V[i][j+k])
				except IndexError:
					V[i][j] = 0.25*(V[i-k][j]+V[i+k-1][j]+V[i][j-k]+V[i][j+k-1])


def S(V,k):
	sum = 0
	divider = 1/(2*k*delta)
	constFrac = ((k*delta)**2)/2

	for i in range(0,nx-k,k):
		for j in range(0,ny-k,k):
			firstFrac = (V[i+k][j]-V[i][j])*divider
			secondFrac = (V[i+k][j+k]-V[i][j+k])*divider
			firstPow = (firstFrac + secondFrac)**2

			firstFrac = (V[i][j+k]-V[i][j])*divider
			secondFrac = (V[i+k][j+k]-V[i+k][j])*divider
			secondPow = (firstFrac + secondFrac)**2

			sum += constFrac*(firstPow + secondPow)
	return sum

def dens_mesh(V,k):
	k2 = k//2
	for i in range(0,nx-k,k):
		for j in range(k,ny-k,k):
			V[i+k2][j+k2] = 0.25*(V[i][j]+V[i+k][j]+V[i][j+k]+V[i+k][j+k])
			V[i+k][j+k2] = 0.5*(V[i+k][j]+V[i+k][j+k])
			V[i+k2][j+k] = 0.5*(V[i][j+k]+V[i+k][j+k])
			V[i+k2][j] = 0.5*(V[i][j]+V[i+k][j])
			V[i][j+k2] = 0.5*(V[i][j]+V[i][j+k])


if __name__ == '__main__':
	start_time = time.time()
	V = np.zeros((nx, ny))
	fill_boundary_conditions(V)
	# np.savetxt('V1.txt', V) # krańcowe warunki brzegowe inaczej
	it = 0
	itArrs = {}
	sArrs = {}
	sPrev = 1
	for k in kArr:
		print("calculating... k: ", str(k))
		sPrev = S(V,k)
		sArr = []
		itArr = []
		while True:
			itArr.append(it)
			it += 1
			relaxate(V,k)
			s = S(V,k)
			sArr.append(s)
			temp = (s-sPrev)/sPrev
			if abs(temp) < TOL:
				break
			sPrev = s
			# print(it, " ",  temp)
			# np.savetxt('V'+str(k)+'.txt', V)

		Vtemp = np.zeros((nx//k, ny//k))
		
		for i in range(0,nx,k):
			for j in range(0,ny,k):
				Vtemp[i//k][j//k] = V[i][j]

		# np.savetxt('V'+str(k)+'.txt', np.rot90(Vtemp))
		plt.imshow(np.rot90(Vtemp), cmap='jet')
		plt.savefig('V'+str(k)+'.png')
		sArrs[k] = sArr
		itArrs[k] = itArr
		if(k != 1):
			dens_mesh(V,k)
		

	plt.clf()
	end_time = time.time()
	print("done ;) time: ", end_time-start_time, "s")
	# plot all s(k) in one plot
	for k in kArr:
		plt.plot(itArrs[k],sArrs[k], label='k='+str(k))	
	plt.legend()
	plt.savefig('s(k).png')