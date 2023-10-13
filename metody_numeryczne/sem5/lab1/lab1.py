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
	ax1.plot(data[0][0], data[0][1], 'p-', label='dt=0.01')
	ax1.plot(data[1][0], data[1][1], '*-', label='dt=0.1')
	ax1.plot(data[2][0], data[2][1], 'gd', label='dt=1')
	ax1.plot(np.linspace(0, 5, 100) ,[math.exp(lam*i) for i in np.linspace(0, 5, 100)], 'k-', label='analitycznie')
	ax1.set_xlabel('t')
	ax1.set_ylabel('y(t)')
	ax2.set_xlabel('t')
	ax2.set_ylabel('y_num(t) - y_dok(t)')

	# zad2 - bład jawnej metody jawnej RK2 (trapezow)
	ax2.plot(data[0][0], [-math.exp(lam*i) + j for i,j in zip(data[0][0],data[0][1])], 'p-', label='dt=0.01')
	ax2.plot(data[1][0], [-math.exp(lam*i) + j for i,j in zip(data[1][0],data[1][1])], '*-', label='dt=0.1')
	ax2.plot(data[2][0], [-math.exp(lam*i) + j for i,j in zip(data[2][0],data[2][1])], 'gd-', label='dt=1')

	ax1.legend(loc='right')
	plt.savefig("zad2.png",bbox_inches='tight', transparent=False)


if __name__ == "__main__":
	
	with open("zad1_1.txt", "r+") as f1:
		y0 = 1.0
		lam = -1.0
		t1 = 0
		t2 = 5
		dt = [0.01,0.1,1.]
		# zad1 - jawna metoda Eulera
		zad1(y0, lam, t1, t2, dt)

		# zad2 - metoda jawna RK2 (trapezow)
		zad2(y0, lam, t1, t2, dt)


