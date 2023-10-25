import math
import numpy as np
import matplotlib.pyplot as plt

def jawna_eulera(y0, lam, t1, t2, dt):
	y = []
	t = [i for i in np.arange(t1,t2+0.0001,dt)]
	yPrev = y0
	temp = y0
	for i in range(1, len(t)+1):
		y.append(temp)
		temp = yPrev + dt*lam*yPrev
		yPrev = temp
	return t, y
def RK2(y0, lam, t1, t2, dt):
	y = []
	t = [i for i in np.arange(t1,t2 + 0.0001,dt)]
	yPrev = y0
	temp = y0
	for i in range(1, len(t)+1):
		k1 = lam*yPrev
		k2 = lam*(yPrev + dt*k1)
		y.append(temp)
		temp = yPrev + dt*(k1+k2)/2
		yPrev = temp
	return t, y
def RK4(y0, lam, t1, t2, dt):
	y = []
	t = [i for i in np.arange(t1,t2 + 0.0001,dt)]
	yPrev = y0
	temp = y0
	for i in range(1, len(t)+1):
		k1 = lam*yPrev
		k2 = lam*(yPrev + dt*k1/2)
		k3 = lam*(yPrev + dt*k2/2)
		k4 = lam*(yPrev + dt*k3)
		y.append(temp)
		temp = yPrev + dt*(k1+2*k2+2*k3+k4)/6
		yPrev = temp
	return t, y


def zad1(y0, lam, t1, t2, dt):
	data = []
	for d in dt:
		data.append(tuple(jawna_eulera(y0, lam, t1, t2, d)))
		
	figure, (ax1, ax2) = plt.subplots(2)
	figure.tight_layout(pad=3.0)
	ax1.plot(data[0][0], data[0][1], 'p-', label='dt=0.01')
	ax1.plot(data[1][0], data[1][1], '*-', label='dt=0.1')
	ax1.plot(data[2][0], data[2][1], 'gd', label='dt=1')
	ax1.plot(np.linspace(0, 5, 100) ,[math.exp(lam*i) for i in np.linspace(0, 5, 100)], 'k-', label='analitycznie')

	ax1.title.set_text('Metoda jawna Eulera')
	ax1.set_xlabel('t')
	ax1.set_ylabel('y(t)')
	ax2.title.set_text('Bład jawnej metody Eulera')
	ax2.set_xlabel('t')
	ax2.set_ylabel('y_num(t) - y_dok(t)')

	# zad1 - bład jawnej metody Eulera
	ax2.plot(data[0][0], [-math.exp(lam*i) + j for i,j in zip(data[0][0],data[0][1])], 'p-', label='dt=0.01')
	ax2.plot(data[1][0], [-math.exp(lam*i) + j for i,j in zip(data[1][0],data[1][1])], '*-', label='dt=0.1')
	ax2.plot(data[2][0], [-math.exp(lam*i) + j for i,j in zip(data[2][0],data[2][1])], 'gd-', label='dt=1')
	ax1.legend(loc='right')
	plt.savefig("zad1.png",bbox_inches='tight', transparent=False)
def zad2(y0, lam, t1, t2, dt):
	data = []
	for d in dt:
		data.append(tuple(RK2(y0, lam, t1, t2, d)))
		
	figure, (ax1, ax2) = plt.subplots(2)
	figure.tight_layout(pad=3.0)

	ax1.plot(data[0][0], data[0][1], 'p-', label='dt=0.01')
	ax1.plot(data[1][0], data[1][1], '*-', label='dt=0.1')
	ax1.plot(data[2][0], data[2][1], 'gd', label='dt=1')
	ax1.plot(np.linspace(0, 5, 100) ,[math.exp(lam*i) for i in np.linspace(0, 5, 100)], 'k-', label='analitycznie')
	
	ax1.title.set_text('Metoda jawna RK2 (trapezow)')
	ax1.set_xlabel('t')
	ax1.set_ylabel('y(t)')
	ax2.title.set_text('Bład jawnej metody RK2 (trapezow)')

	ax2.set_xlabel('t')
	ax2.set_ylabel('y_num(t) - y_dok(t)')

	# zad2 - bład jawnej metody jawnej RK2 (trapezow)
	ax2.plot(data[0][0], [-math.exp(lam*i) + j for i,j in zip(data[0][0],data[0][1])], 'p-', label='dt=0.01')
	ax2.plot(data[1][0], [-math.exp(lam*i) + j for i,j in zip(data[1][0],data[1][1])], '*-', label='dt=0.1')
	ax2.plot(data[2][0], [-math.exp(lam*i) + j for i,j in zip(data[2][0],data[2][1])], 'gd-', label='dt=1')

	ax1.legend(loc='right')
	plt.savefig("zad2.png",bbox_inches='tight', transparent=False)
def zad3(y0, lam, t1, t2, dt):
	data = []
	for d in dt:
		data.append(tuple(RK4(y0, lam, t1, t2, d)))
		
	figure, (ax1, ax2) = plt.subplots(2)
	figure.tight_layout(pad=3.0)

	ax1.plot(data[0][0], data[0][1], 'p-', label='dt=0.01')
	ax1.plot(data[1][0], data[1][1], '*-', label='dt=0.1')
	ax1.plot(data[2][0], data[2][1], 'gd', label='dt=1')
	ax1.plot(np.linspace(0, 5, 100) ,[math.exp(lam*i) for i in np.linspace(0, 5, 100)], 'k-', label='analitycznie')
	
	ax1.title.set_text('Metoda jawna RK4')
	ax1.set_xlabel('t')
	ax1.set_ylabel('y(t)')

	ax2.title.set_text('Bład jawnej metody RK4')
	ax2.set_xlabel('t')
	ax2.set_ylabel('y_num(t) - y_dok(t)')

	# zad3 - bład jawnej metody jawnej RK4
	ax2.plot(data[0][0], [-math.exp(lam*i) + j for i,j in zip(data[0][0],data[0][1])], 'p-', label='dt=0.01')
	ax2.plot(data[1][0], [-math.exp(lam*i) + j for i,j in zip(data[1][0],data[1][1])], '*-', label='dt=0.1')
	ax2.plot(data[2][0], [-math.exp(lam*i) + j for i,j in zip(data[2][0],data[2][1])], 'gd-', label='dt=1')

	ax1.legend(loc='right')
	plt.savefig("zad3.png",bbox_inches='tight', transparent=False)

def obwodRLC(R, L, C, omega, t0, t1, dt, Q0, I0):
	t = [i for i in np.arange(t0,t1 + 0.0001,dt)]
	Q = [Q0]
	I = [I0]
	V = lambda t, omega: 10*math.sin(omega*t)
	for i in range(1, len(t)):
		kQ1 = I[i-1]
		kI1 = V(t[i-1], omega)/L - Q[i-1]/(L*C) - R*I[i-1]/L
		kQ2 = I[i-1] + dt*kI1/2
		kI2 = V(t[i-1] + dt/2, omega)/L - (Q[i-1] + dt*kQ1/2)/(L*C) - R*(I[i-1] + dt*kI1/2)/L		
		kQ3 = I[i-1] + dt*kI2/2
		kI3 = V(t[i-1] + dt/2, omega)/L - (Q[i-1] + dt*kQ2/2)/(L*C) - R*(I[i-1] + dt*kI2/2)/L
		kQ4 = I[i-1] + dt*kI3
		kI4 = V(t[i-1] + dt, omega)/L - (Q[i-1] + dt*kQ3)/(L*C) - R*(I[i-1] + dt*kI3)/L
		Q.append(Q[i-1] + dt/6*(kQ1 + 2*kQ2 + 2*kQ3 + kQ4))
		I.append(I[i-1] + dt/6*(kI1 + 2*kI2 + 2*kI3 + kI4))
	return t, Q, I

def zad4( R, L, C, om0, t0, t1, dt, Q0, I0):
	figure, (ax1, ax2) = plt.subplots(2)
	figure.tight_layout(pad=3.0)
	for omega in omegi:
		t, Q, I = obwodRLC(R, L, C, omega, t0, t1, dt, 0, 0)
		ax1.plot(t, Q, label=f"{omega/om0} \u03C9")
		ax2.plot(t, I, label=f"{omega/om0} \u03C9")
		ax1.title.set_text('Q(t)')
		ax1.set_xlabel('t')
		ax1.set_ylabel('Q(t)')
		ax2.title.set_text('I(t)')
		ax2.set_xlabel('t')
		ax2.set_ylabel('I(t)')
		ax1.legend(loc='right')

	plt.savefig("zad4.png",bbox_inches='tight')

if __name__ == "__main__":
	
	y0 = 1.0
	lam = -1.0
	t1 = 0
	t2 = 5
	dt = [0.01,0.1,1.]
	# zad1 - jawna metoda Eulera
	zad1(y0, lam, t1, t2, dt)

	# zad2 - metoda jawna RK2 (trapezow)
	zad2(y0, lam, t1, t2, dt)

	# zad3 - metoda jawna RK4
	zad3(y0, lam, t1, t2, dt)

	# zad4 - RRZ
	dt = 0.0001
	R = 100
	L = 0.1
	C = 0.001
	V0 = 10
	om0 = 1/(math.sqrt(L*C))
	t0 = 0
	t1 = 8*math.pi/om0
	omegi = [0.5*om0, 0.8*om0, om0, 1.2*om0]
	
	zad4(R, L, C, om0, t0, t1, dt, 0, 0)