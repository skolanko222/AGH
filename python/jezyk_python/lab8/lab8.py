# zad1
print("zad1")
def zad1(f,n):
	with open(f) as plik:
		temp = plik.readlines()
		print([item.strip() for item in temp[:n] ])
		print([i.strip() for i in temp[-n::]])
		print([i.strip() for i in temp[::n]])
		plik.seek(0)
		print([line.split()[n] for line in plik if n < len(line.split())])
		plik.seek(0)
		print( [line[n] for line in plik if n < len(line)])

print(zad1("lab5.py",3))

# zad2
print("zad2")
import glob

fname = [i for i in glob.glob("data*.in")]
print(fname)

def read_data(arr):
	w = {}
	for i in arr:
		with open(i) as plik:
			for k,j in enumerate(plik):
				w.setdefault(k,[]).append(float(j))
	return w

import numpy as np

nazwa = "zad2.txt"

def write_data(data,filename):
	with open(filename, "w") as plik:
		for i, line_data in data.items():
			plik.write(" ".join([str(i),str(np.average(line_data)),str(np.std(line_data)),"\n"]))
write_data(read_data(fname),nazwa)

# zad3
print("zad3")

nazwa = "data5.in"
with open("generate.py","w") as plik:
	plik.write('''import numpy
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
plt.savefig('res.pdf')''')

# zad4
print("zad4")
fname = [i for i in glob.glob("2*.txt")]
print(fname)

# zad5
print("zad5")

# zad6
print("zad6")
