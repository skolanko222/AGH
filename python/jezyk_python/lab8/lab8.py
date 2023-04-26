# zad1
def read_n(f,n):
	with open(f) as plik:
		return [plik.readline().replace("\n","") for _ in range(n)]

def read_n_last(f,n):
	with open(f) as plik:
		return [i.replace("\n","") for i in plik.readlines()[-n::]]

def read_co_n(f,n):
	with open(f) as plik:
		return [i.replace("\n","") for i in plik.readlines()[::n]]

def read_n_slowo_z_wiersza(f,n):
	with open(f) as plik:
		return [line.split()[n] for line in plik]

def read_n_znak_z_wiersza(f,n):
	with open(f) as plik:
		return [line[n] for line in plik]

print(read_n_znak_z_wiersza("zad1.txt",2))

# zad2
import glob
import numpy as np

wiersz = []
fnames = [open(i) for i in glob.iglob('data*.io')]
for plik in fnames:
	wiersz.append([[float(i) for i in line.split()] for line in plik])


for i in fnames:
	i.close()

out = open("zad2.out", "w")
for i in range(len(wiersz[0])):
	out.write(str(i) + " ")
	out.write(str(np.mean([wiersz[j][i] for j in range(len(wiersz))])) + " ")
	out.write(str(np.std([wiersz[j][i] for j in range(len(wiersz))])) + "\n")
out.close()

#print(wiersz)