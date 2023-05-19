# zad 1
import random
import matplotlib.pyplot as plt
class IFS:
    '''klasa implementujaca Iterated Function System'''
    def __init__(self, a, b):
        self.przek = a
        self.prawdop = b
        self.x = 0
        self.y = 0

        self.xarr = []
        self.yarr = []

    def przeksztalcenie(self, iteracje):
        for _ in range(iteracje):
            wsp = random.choices(self.przek, self.prawdop)[0]
            self.x, self.y = self.x*wsp[0] + self.y*wsp[1] + wsp[2], self.x*wsp[3] + self.y*wsp[4] + wsp[5]
            self.xarr.append(self.x)
            self.yarr.append(self.y)

    def draw(self):
        plt.plot(self.xarr, self.yarr, 'bo', markersize=1)
        plt.show()

# zad2

class Wektor3D:
    '''trojwymiarowy wektor'''
    def __init__(self,x,y,z):
        self.x = x
        self.y = y
        self.z = z
    def __add__(self,other):
        return Wektor3D(self.x + other.x, self.y + other.y, self.z + other.z)
    def __sub__(self, other):
        return Wektor3D(self.x - other.x, self.y - other.y, self.z - other.z)
    def __mul__(self,val):
        return Wektor3D(self.x*val, self.y*val, self.z*val)
    __rmul__ = __mul__
    
    def __str__(self):
        return f"({self.x},{self.y},{self.z})"
    
    def iloczyn_skalarny(self, other):
        return self.x*other.x + self.y*other.y + self.z*other.z
    def iloczyn_wektorowy(self, other):
        return Wektor3D(self.y*other.z - self.z*other.y, self.z*other.x - self.x*other.z, self.x*other.y - self.y*other.x)
    def iloczyn_mieszany(self, other1, other2):
        return self.iloczyn_skalarny(other1.iloczyn_wektorowy(other2))

def strumien_indukcji(vec1, vec2):
    try:
        return vec1.iloczyn_skalarny(vec2)
    except AttributeError:
        print("zly argument!")

def sila_lorentza(q,E,v,B):
    return q*(E+v.iloczyn_wektorowy(B))

def praca_sily_Lorenza(q,E,v):
    return q*(E.iloczyn_skalarny(v))

if __name__ == '__main__':
    # zad1
    objIFS1 = IFS(((0.787879, -0.424242, 1.758647, 0.242424, 0.859848, 1.408065), (-0.121212, 0.257576, -6.721654, 0.151515, 0.05303, 1.377236), (0.181818, -0.136364, 6.086107, 0.090909, 0.181818, 1.568035)), (0.90, 0.05, 0.05))
    objIFS2 = IFS(((0.824074, 0.281428, -1.88229, -0.212346, 0.864198, -0.110607), (0.088272, 0.520988, 0.78536, -0.463889, -0.377778, 8.095795)),  (0.8, 0.2))
    objIFS1.przeksztalcenie(10000)
    objIFS1.draw()
    objIFS2.przeksztalcenie(10000)
    objIFS2.draw()


    # zad2
    print("zad2")
    ob1 = Wektor3D(1,0,0)
    ob2 = Wektor3D(0,1,0)
    ob3 = Wektor3D(6,4,0)
    print(2*ob1.iloczyn_wektorowy(ob2))

    # zad 3
    print("zad3")


    print(strumien_indukcji(ob1,ob2))
    print(sila_lorentza(10,ob3,ob1,ob2))
    print(praca_sily_Lorenza(10,ob3,ob2))

test = Iterator_2(100000)
ilosc = {}
i=0
for n in range(1,11):
    for elz in test:
        #print(elz)
        if elz[0] < n*0.1 and elz[1] < n*0.1:
            i+=1
            ilosc[n]=i
    ilosc[n]=ilosc[n]/1000
    i=0
print("Wyliczone:")
print(ilosc)

ilosc_py={}
i=0
temp_list = [(random.random(), random.random()) for _ in range(100000)]
for n in range(1,11):
    for j in temp_list:
    #print(j)
        if j[0] < n*0.1 and j[1] < n*0.1:
            i+=1
            ilosc_py[n]=i
    ilosc_py[n]=ilosc_py[n]/1000
    i=0

print("Generator Pythona:")
print(ilosc_py)