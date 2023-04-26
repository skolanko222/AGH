import numpy
import glob
import matplotlib.pyplot as plt

lista_plikow = glob.glob('data*.in')
for i in lista_plikow:
	y=numpy.loadtxt(i, unpack=True)
	x=range(len(y))
	plt.plot(x, y, 'o')
x,y,z = numpy.loadtxt('zad2.txt', unpack=True)
plt.errorbar(x, y, marker='*', yerr=z)
plt.xlabel('x')
plt.savefig('res.pdf')