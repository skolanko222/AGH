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

srednie = {}
fnames = [open(i) for i in glob.iglob('data*.io')]
while fnames:
	wiersz = []
	for plik in fnames:
		wiersz.extend([float(j) for line in plik for j in line.split()])
	


print(srednie)