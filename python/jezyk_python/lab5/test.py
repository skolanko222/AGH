



#zad3
def zad3(x_arr,y_arr):
    x_sr = sum(x_arr) / len(x_arr)
    print(x_sr)
    D = sum((i - x_sr)**2 for i in x_arr)
    
zad3([1,2,3],[1,2,3])


#zad4 
def zad4(fun, seq):
    ret = 0
    while(seq):	
        ret += fun(seq.pop(),seq.pop())
    print(ret)
        
zad4(lambda x,y : x*y, [1,2,3,4,5,6])

#zad5
a = [[1,2,3,4,5],[3,4,5,6,7]]
b = [[2,1,3,7,5],[2,9,5,1,7]]
print(list(map(max,a)))

print(list(map(max,zip(*a))))

print("huj")
print(list(map(sum, zip(list(i, j) for i, j in zip(a,b)))))
    