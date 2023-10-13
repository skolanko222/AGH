import numpy as np
import matplotlib.pyplot as plt

figure, (ax1, ax2) = plt.subplots(2)


def to_float(x):
	try:
		return float(x)
	except ValueError:
		return 0
arr = []
arr2 = []

with open("zad1_1.txt") as file, open("zad1_2.txt") as file2:
	for line1,line2 in zip(file.readlines(),file2.readlines()):
			arr.append([to_float(i) for i in line1.split(' ') if i is not '\n'])
			arr2.append([to_float(i) for i in line2.split(' ') if i is not '\n'])


ax1.plot(arr[0], arr[1], 'b-', label='dt=0.01')
ax1.plot(arr[2], arr[3], 'r-', label='dt=0.1')
ax1.plot(arr[4], arr[5], 'g-', label='dt=1')

ax2.plot(arr2[0], arr2[1], 'b-', label='dt=0.01')
ax2.plot(arr2[2], arr2[3], 'r-', label='dt=0.1')
ax2.plot(arr2[4], arr2[5], 'g-', label='dt=1')

l1 = plt.legend()
ax1.set_xlabel('t')
ax1.set_ylabel('y(t)')
ax2.set_xlabel('t')
ax2.set_ylabel('y_num(t) - y_dok(t)')
plt.savefig("zad1.png",bbox_inches='tight', transparent=False)
