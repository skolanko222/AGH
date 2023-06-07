from setuptools import setup, Extension
setup(name='mod', version='1.0', ext_modules=[Extension('mod', sources=['mod.c'])])
import sys
sys.path.append("build/lib.linux-x86_64-3.10")
import mod
import random
import time

# zad1
print(mod.met(1,2))
print(mod.met(1,2,5))
print(mod.met(1,2,5,[2,3,4]))
# zad2
def sortowanie_wstawianie(A):
    for i in range(1,len(A)):
        temp = A[i]
        j = i - 1
        while j>0 and A[j] > temp:
            A[j+1] = A[j]
            j = j - 1
        A[j + 1] = temp
        
rozmiary = [10,100,1000,10000]
for n in rozmiary:
	A = [random.randint(0,100000) for _ in range(n)]
	B = A.copy()
    
	t1 = time.time_ns()
	sortowanie_wstawianie(A)
	t2 = time.time_ns()
	
	t3 = time.time_ns()
	B = mod.sortowanie_c(B)
	t4 = time.time_ns()

	print(f"{n=} czas python: {t2-t1} czas c: {t4-t3}")


# zad3 
mod.nwd({12:123,45:344})
