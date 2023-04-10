from math import sqrt
import random

#zad2
arr1 = [random.randrange(0,20) for _ in range(100)]
arr2 = [random.randrange(0,20) for _ in range(100)]

arr_tuple = list(filter(lambda x : sum(x) > 3 and sum(x) < 15, [(i,j) for i, j in zip(arr1, arr2)]))
print("zad2", arr_tuple)

#zad3
def zad3(x_arr,y_arr):
    x_sr = sum(x_arr) / len(x_arr)
    y_sr = sum(y_arr) / len(y_arr)
    print(x_sr)
    D = sum((i - x_sr)**2 for i in x_arr)
    a = sum([j*(i-x_sr) for i,j in zip(x_arr,y_arr)])/D
    b = y_sr - a*x_sr
    d_y = sqrt(sum([(j-(a*i+b))**2 for i,j in zip(x_arr,y_arr)]))
    d_a = d_y/sqrt(D)
    d_b = d_y*sqrt(1/len(x_arr) + (x_sr**2)/D)
    return {'a':a, 'b':b, 'niep_a': d_a, 'niep_b': d_b }
    
print("zad3",zad3([1,2,3],[2,4,6]))

#zad4 
def zad4(fun, seq):
    ret = 0
    while(len(seq)>1):	
       seq.append( fun(seq.pop(),seq.pop()))
       #print(seq, end=' ')
    return ret
    
print("zad4: ", zad4(lambda x,y : x*y, [1,2,3,4,5,6]))

#zad5
a = [[1,2,3,4,5], [3,4,5,6,7]]
b = [[2,1,3,7,5], [2,9,5,1,7]]

#a
print(list(map(max,a)))

#b
print(list(map(max,zip(*a))))

#c
addit = [list(map(sum, ((j,k) for j,k in zip(i,j)) ))  for i, j in zip(a,b)]
print(addit)

