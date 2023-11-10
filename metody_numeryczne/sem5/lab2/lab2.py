import numpy as np
import math
import matplotlib.pyplot as plt


def mTrap_picarda(beta, N, gamma, tMax, dt, u0, TOL):
	t = [i for i in np.arange(0, tMax, dt)]
	u = [u0]
	alpha = beta*N - gamma
	for i in range(1, len(t)):
		un = u[i-1]
		un0 = u[i-1]
		for j in range(20):
			try:#(alpha*un0 - beta*un0**2 + alpha*(un + dt*(alpha*un - beta*un**2)) - beta*(un + dt*(alpha*un - beta*un**2))**2))
				u[i] = (un0 + dt/2*(alpha*un0 - beta*un0**2 + (alpha*un - beta*un**2))) 
			except IndexError:
				u.append(un0 + dt/2*(alpha*un0 - beta*un0**2 + (alpha*un - beta*un**2)))
			if abs(u[i] - un) < TOL:
				break
			un = u[i]
	return t, u

def mTrap_newtona(beta, N, gamma, tMax, dt, u0, TOL):
	t = [i for i in np.arange(0, tMax, dt)]
	u = [u0]
	alpha = beta*N - gamma
	for i in range(1, len(t)):
		un = u[i-1]
		un0 = u[i-1]

		for j in range(20):
			licznik = un - un0 - dt/2*(alpha*un0 - beta*un0**2 + (alpha*un - beta*un**2))
			mianownik = 1 - dt/2*(alpha - 2*beta*un)
			try:
				u[i] = un - licznik/mianownik
			except IndexError:
				u.append(un - licznik/mianownik)
			if abs(u[i] - un) < TOL:
				break
			un = u[i]
	return t, u

def mRK2(beta, N, gamma, tMax, dt, u0, TOL):
	# tablica Butchera
	c1 = 1/2 - math.sqrt(3)/6
	c2 = 1/2 + math.sqrt(3)/6
	a11 = a22 = 1/4
	a21 = 1/4 + math.sqrt(3)/6
	a12 = 1/4 - math.sqrt(3)/6
	b1 = 1/2 
	b2 = 1/2
	alpha = beta*N - gamma
	t = [i for i in np.arange(0, tMax, dt)]
	u = [u0]
	for i in range(1, len(t)):
		un = u[i-1]
		un1 = u[i-1]
		un2 = u[i-1]
				
		for j in range(20):
			F1 = un1 - un - dt*(a11*(alpha*un1 - beta*un1**2) + a12*(alpha*un2 - beta*un2**2))
			F2 = un2 - un - dt*(a21*(alpha*un1 - beta*un1**2) + a22*(alpha*un2 - beta*un2**2))			
			m11 = 1 - dt/2*(alpha - 2*beta*un1) #23
			m12 = -dt/2*a12*(alpha - 2*beta*un2)
			m21 = -dt/2*a21*(alpha - 2*beta*un1)
			m22 = 1 - dt/2*(alpha - 2*beta*un2)
			det = m11*m22 - m12*m21
			dU1 = (m12*F2 - m22*F1)/det #27
			dU2 = (m21*F1 - m11*F2)/det
			
			un1 += dU1 #20
			un2 += dU2
			if abs(dU1 - un1 ) < TOL or abs(dU2 - un2) < TOL:
				break
			try:
				u[i] = un + dt*(b1*(alpha*un1 - beta*un1**2) + b2*(alpha*un2 - beta*un2**2))
			except IndexError:
				u.append(un + dt*(b1*(alpha*un1 - beta*un1**2) + b2*(alpha*un2 - beta*un2**2)))
	return t, u	


def zad1(beta, N, gamma, tMax, dt, u0, TOL):
	t, u = mTrap_picarda(beta, N, gamma, tMax, dt, u0, TOL)
	plt.plot(t, u, label='u(t)')
	plt.plot(t, [N - i for i in u], label='z(t)')
	plt.title('Metoda Picarda')
	plt.legend()
	plt.xlabel('t')
	plt.ylabel('z(t), u(t)')
	plt.savefig('zad1.png')
	plt.close()

def zad2(beta, N, gamma, tMax, dt, u0, TOL):
	t1, u1 = mTrap_newtona(beta, N, gamma, tMax, dt, u0, TOL)
	plt.plot(t1, u1, label='u(t)')
	plt.plot(t1, [N - i for i in u1], label='z(t)')
	plt.title('Metoda Newtona')
	plt.legend()
	plt.xlabel('t')
	plt.ylabel('z(t), u(t)')
	plt.savefig('zad2.png')
	plt.close()

def zad3(beta, N, gamma, tMax, dt, u0, TOL):
	t1, u1 = mRK2(beta, N, gamma, tMax, dt, u0, TOL)
	plt.plot(t1, u1, label='u(t)')
	plt.plot(t1, [N - i for i in u1], label='z(t)')
	plt.title('Metoda RK2')
	plt.legend()
	plt.xlabel('t')
	plt.ylabel('z(t), u(t)')
	plt.savefig('zad3.png')
	plt.close()

if __name__ == '__main__':
	beta = 0.001
	N = 500
	gamma = 0.1
	tMax = 100
	dt = 0.1
	u0 = 1
	TOL = 10**(-6)
	zad1(beta, N, gamma, tMax, dt, u0, TOL)
	zad2(beta, N, gamma, tMax, dt, u0, TOL)
	zad3(beta, N, gamma, tMax, dt, u0, TOL)