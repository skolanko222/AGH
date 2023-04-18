#zadanie 1
print("zad1")
import time
import random
import sys
from math import sqrt
from math import hypot

powt=1000
N=10000
def forStatement():
	arr = []
	for i in range(N):
		arr.append(i)


def listComprehension():
	arr = [i for i in range(N)]


def mapFunction():
	arr = map(lambda x : x ,range(N))


def generatorExpression():
	arr = (i for i in range(N))


def tester(a):
	t1 = time.time_ns()
	for _ in range(powt):
		a()
	t2 = time.time_ns()
	return t2 - t1

print(sys.version)
test=(forStatement, listComprehension, mapFunction, generatorExpression)
for testFunction in test:
	print(testFunction.__name__.ljust(20), '=>', tester(testFunction))


#zadanie 2
print("zad2")

n=100000

points = ((random.uniform(-1.,1),random.uniform(-1.,1)) for _ in range(n))
hit = filter(lambda point : hypot(*point) < 1.,points)
print('pi = ',4*len(list(hit))/n)


#zadanie 3
print("zad3")

def zad3(x_arr, y_arr):
	x_sr = sum(x_arr)/len(x_arr)
	y_sr = sum(y_arr)/len(y_arr)
	D = sum((i - x_sr)**2 for i in x_arr)
	a = sum(map(lambda x,y : (y*(x-x_sr)), x_arr, y_arr))/D
	b = y_sr - a*x_sr
	d_y = sqrt(sum(list(map(lambda x,y : (y -(a*x+b))**2,x_arr,y_arr))))
	d_a = d_y/sqrt(D)
	d_b = d_y*sqrt(1/len(x_arr) + (x_sr**2/D))
	return {'a':a, 'b': b, 'd_a':d_a, 'd_x': d_b}

print(zad3([1,2,3,4,5],[1,2,3,4,5]))


#zadanie 4
print("zad4")
def myreduce(fun, seq):
	ret = 0
	while(len(seq) > 1):
		seq.append(fun(seq.pop(),seq.pop()))
	return seq[0]

print(myreduce(lambda x,y : x*y, [1,2,3,4]))


#zadanie 5
print("zad5")

n = 5
arr1 = [[random.randint(0,20) for _ in range(5)]for _ in range(5)]
arr2 = [[[random.randint(0,20) for _ in range(5)] for _ in range(5)] for _ in range(n)] # lista n macierzy
print("arr2: ", arr2)

a = list(map(max,arr1)) 
print(f'{a=}')

b = list(map(max,*arr1))
print(f'{b=}')

c = []
#c.append[list(map(lambda x: sum(*x),zip(*arr2)))]




