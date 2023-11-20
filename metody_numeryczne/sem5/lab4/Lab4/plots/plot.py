import numpy as np
import matplotlib.pyplot as plt

# S global
print('Plotting S global')

plt.figure()

gs06 = np.loadtxt('gs_0.6.txt')
gs1 = np.loadtxt('gs_1.txt')

plt.plot(gs06[:, 0], gs06[:, 1], label='$\omega_G = 0.6$')
plt.plot(gs1[:, 0], gs1[:, 1], label='$\omega_G = 1.0$')

plt.xscale('log')
plt.legend()
plt.grid()
plt.xlabel('it')
plt.ylabel('S(it)')
plt.title('Zmiana całki S(it) (relaksacja globalna)')

plt.savefig("gs.png")

# S local
print('Plotting S local')

plt.figure()

lsl = np.loadtxt('ls_1.txt')
ls14 = np.loadtxt('ls_1.4.txt')
lsl8 = np.loadtxt('ls_1.8.txt')
lsl9 = np.loadtxt('ls_1.9.txt')

plt.plot(lsl[:, 0], lsl[:, 1], label='$\omega_L = 1.0$')
plt.plot(ls14[:, 0], ls14[:, 1], label='$\omega_L = 1.4$')
plt.plot(lsl8[:, 0], lsl8[:, 1], label='$\omega_L = 1.8$')
plt.plot(lsl9[:, 0], lsl9[:, 1], label='$\omega_L = 1.9$')

plt.xscale('log')
plt.legend()
plt.grid()
plt.xlabel('it')
plt.ylabel('S(it)')
plt.title('Zmiana całki $S(it)$ (relaksacja lokalna)')

plt.savefig("ls.png")

for v in [0.6, 1]:
	# Vn
	print('Plotting Vn ' + str(v))

	plt.figure()

	vn = np.loadtxt('vn_' + str(v) + '.txt')

	plt.tricontourf(vn[:, 0], vn[:, 1], vn[:, 2], levels=np.linspace(min(vn[:, 2]), max(vn[:, 2]), 999))
	plt.colorbar(ticks=np.linspace(min(vn[:, 2]), max(vn[:, 2]), 11))

	plt.title('Zrelaksowany potencjał $V(x,y)$ ($\omega_G = ' + str(v) + '$)')

	plt.savefig('vn_' + str(v) + '.png')

	# Err

	print('Plotting Err ' + str(v))

	plt.figure()

	err = np.loadtxt('err_' + str(v) + '.txt')

	plt.tricontourf(err[:, 0], err[:, 1], err[:, 2], levels=np.linspace(min(err[:, 2]), max(err[:, 2]), 999))
	plt.colorbar(ticks=np.linspace(min(err[:, 2]), max(err[:, 2]), 11))

	plt.title('Błąd relaksacji ($\omega_G = ' + str(v) + '$)')

	plt.savefig('err_' + str(v) + '.png')