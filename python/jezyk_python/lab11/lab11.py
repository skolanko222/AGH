# zad1
# Proszę napisać iterator zwracający kolejne liczby pierwsze z zadanego zakresu x, y
class Pierwsze:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def __iter__(self):
        return self
    def __next__(self):
        while True:
            if self.x < self.y:
                for i in range(2,self.x):
                    #print(i,self.x)
                    if self.x % i == 0 and i != 1:
                        break
                else:
                    #print("pierw")
                    self.x +=1
                    return self.x -1
                self.x +=1
            else:
                raise StopIteration
            

class Pierwszev2:
    def __init__(self,x,y):
        self.x = x
        self.y = y
    def __iter__(self):
        return Pierwszev2(self.x,self.y)
    def __next__(self):
        while True:
            if self.x < self.y:
                for i in range(2,self.x):
                    #print(i,self.x)
                    if self.x % i == 0 and i != 1:
                        break
                else:
                    #print("pierw")
                    self.x +=1
                    return self.x -1
                self.x +=1
            else:
                raise StopIteration
        
        
        
# zad2
class Pseudoloswe:
    def __init__(self,n,m = 2**31 - 1.,a = 7**5,c = 0,x = 1):
        self.n = n
        self.m = 2**31 - 1.
        self.a = 7**5
        self.c = 0
        self.x = 1
        self.i = 0
    def __iter__(self):
        return self
    def __next__(self):
        if self.i < self.n:
            self.x = (self.a*self.x + self.c)%self.m
            self.i+=1
            return self.x/self.m
        raise StopIteration

# zad3

import abc
class Calka(abc.ABC):
    def __init__(self,fun,a,b,metoda):
        self.fun = fun
        self.a = a
        self.b = b
        self.metoda
    @abc.abstractmethod
    def oblicz(self):
        pass

class Simpson(Calka):
    pass
class MonteCarlo(Calka):
    pass


# main
if __name__ == "__main__":
    print("zad1")
    temp = Pierwsze(1,20)
    temp2 = Pierwszev2(1,5)
    for i in temp:
        for j in temp:
            print(f"({i},{j}) ", end = ' ')
    print()

    for i in temp2:
        for j in temp2:
            print(f"({i},{j}) ", end = ' ')
        print()

    #zad2
    result1 = {}
    result2 = {}
    for i in range(1,11): 
        arr=[]  
        iterator = Pseudoloswe(2*100000)
        result1[i] = 0
        for _ in range(2*100000):
            try:
                a = next(iterator)
                b = next(iterator)
                if a < i*0.1 and b < i*0.1:
                    arr.append((a,b))
                    result1[i] +=1    
            except StopIteration:
                pass
        result1[i] /=100000
    import random
    for i in range(1,11): 
        arr=[]  
        rand_num =  [(random.random(), random.random()) for _ in range(100000)]
        result2[i] = 0
        for j in rand_num:
            try:
                a = j[0]
                b = j[1]
                if a < i*0.1 and b < i*0.1:
                    arr.append((a,b))
                    result2[i] += 1
            except StopIteration:
                pass
        result2[i] /=100000
    print("zad2")
    print(result1)
    print(result2)
    # zad3

    try:
        a = Calka(1,2,3, lambda x : x**2)
    except TypeError:
        print("klasa abstrakcyjna nie moze miec instancji")
