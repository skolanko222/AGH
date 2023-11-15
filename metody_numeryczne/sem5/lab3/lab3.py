import numpy as np
import math
import matplotlib.pyplot as plt

def f(t, x, v, alpha):
	return v

def g(t, x, v, alpha):
	return alpha*(1 - x**2)*v - x

def metodaTrapezow(x0, v0, dt0, alpha):
	a11 = 1
	a12 = -dt0/2.
	xn_1 = x0
	vn_1 = v0
	dx = 0
	dv = 0

	while abs(dx) < 1e-10 and abs(dv) < 1e-10:
		a21 = -dt0/2.*(-2*alpha*xn_1*vn_1 - 1)
		a22 = 1 - dt0/2.*alpha*(1 - xn_1**2)
		F = xn_1 - x0 - dt0/2.*(f(0, x0, v0, alpha) + f(0, xn_1, vn_1, alpha))
		G = vn_1 - v0 - dt0/2.*(g(0, x0, v0, alpha) + g(0, xn_1, vn_1, alpha))
		dx = (-F*a22 + G*a12)/(a11*a22 - a12*a21)
		dv = (F*a21 - G*a11)/(a11*a22 - a12*a21)
		x0 = xn_1
		v0 = vn_1
		xn_1 += dx
		vn_1 += dv
	return xn_1, vn_1    

def RK2(xn, vn, dt, alpha):
	k1x = f(0, xn, vn, alpha)
	k1v = g(0, xn, vn, alpha)
	k2x = f(0, xn + dt*k1x, vn + dt*k1v, alpha)
	k2v = g(0, xn + dt*k1x, vn + dt*k1v, alpha)
	xn1 = xn + dt/2.*(k1x + k2x)
	vn1 = vn + dt/2.*(k1v + k2v)
	return xn1, vn1


def E(yn_22, yn_21, p):
	return (yn_22 - yn_21)/(2**p - 1)



def rozwizanie(x0, v0, dt0, alpha, S, p, tmax, TOL1, FUN):
	xArr = [x0]
	vArr = [v0]
	tArr = [0]
	dtArr = [dt0]
	t = 0
	while t < tmax:
		xn1, vn1 = FUN(xArr[-1], vArr[-1], dt0, alpha)
		xn2, vn2 = FUN(xn1, vn1, dt0, alpha)
		xn21, vn21 = FUN(xArr[-1], vArr[-1], dt0*2, alpha)
		Ex = E(xn2, xn21, p)
		Ev = E(vn2, vn21, p)
		if max(abs(Ex), abs(Ev)) < TOL1:
			t += dt0*2
			xArr.append(xn2)
			vArr.append(vn2)
			tArr.append(t)
			dtArr.append(dt0)
		dt0 = (S*TOL1/max(abs(Ex), abs(Ev)))**(1/(p+1))*dt0

	return xArr, vArr, tArr, dtArr

def zad1(x0, v0, dt0, alpha, S, p, tmax, TOL1, TOL2, RK2):
	for i in [RK2, metodaTrapezow]:
		xArr1, vArr1, tArr1, dtArr1 = rozwizanie(x0, v0, dt0, alpha, S, p, tmax, TOL1, i)
		xArr2, vArr2, tArr2, dtArr2 = rozwizanie(x0, v0, dt0, alpha, S, p, tmax, TOL2, i)

		fig, axs = plt.subplots(2, 2, figsize=(10, 10))

		axs[0, 0].set_ylim([-3, 3])
		axs[0, 1].set_ylim([-10, 10])
		axs[1, 0].set_ylim([0, 1])
		axs[1, 1].set_ylim([-8, 8])

		axs[0, 0].plot(tArr1, xArr1, 'p-', label='dt=0.01')
		axs[0, 0].plot(tArr2, xArr2, label='dt=0.00001')
		axs[0, 0].title.set_text('x(t)')
		axs[0, 0].set_xlabel('t')
		axs[0, 0].set_ylabel('x(t)')
		axs[0, 0].legend(loc='right')

		axs[0, 1].plot(tArr1, vArr1, 'p-', label='dt=0.01')
		axs[0, 1].plot(tArr2, vArr2, label='dt=0.00001')
		axs[0, 1].title.set_text('v(t)')
		axs[0, 1].set_xlabel('t')
		axs[0, 1].set_ylabel('v(t)')
		axs[0, 1].legend(loc='right')

		axs[1, 0].plot(tArr1, dtArr1, 'p-', label='dt=0.01')
		axs[1, 0].plot(tArr2, dtArr2, label='dt=0.00001')
		axs[1, 0].title.set_text('dt(t)')
		axs[1, 0].set_xlabel('t')
		axs[1, 0].set_ylabel('dt(t)')
		axs[1, 0].legend(loc='right')

		axs[1, 1].plot(xArr1, vArr1, 'p-', label='dt=0.01')
		axs[1, 1].plot(xArr2, vArr2, label='dt=0.00001')
		axs[1, 1].title.set_text('v(x)')
		axs[1, 1].set_xlabel('x')
		axs[1, 1].set_ylabel('v')
		axs[1, 1].legend(loc='right')
		if i == RK2:
			plt.savefig("zad1_RK2.png")
		else:
			plt.savefig("zad1_metodaTrapezow.png")
	


if __name__ == "__main__":
	x0 = 0.01
	v0 = 0
	dt0 = 1
	S = 0.75
	p = 2
	tmax = 40
	alpha = 5
	TOL1 = 1e-2
	TOL2 = 1e-5
	zad1(x0, v0, dt0, alpha, S, p, tmax, TOL1, TOL2, RK2)
