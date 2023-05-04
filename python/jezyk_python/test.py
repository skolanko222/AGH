# Proszę utworzyć moduł(do modułu oraz do każdej funckji w nim zdefiniowanej, proszę dodać łańcuch dokumentacyjny, który proszę wyświetlić po imporcie modułu) a w nim proszę zdefiniować:

#1.1 Funkcję dokonującą przekształcenia (L-system) wyrażenia według schematu F-> F+F-F-F+F. Stan początkowy 'F','+' obrót w lewo o 90 stopni, '-' obrót w prawo o 90 stopni. Wynik proszę narysować(np. dla 1,3 i 5 przekształceń)
# Proszę zgłosić wyjątek jeżeli schemat zawiera różne litery lub inne znaki niż 'F','+' i '-'.
# Wynik proszę narysować w oknie graficznym jako linie.
#print("Zadanie 1.1")
import matplotlib.pyplot as plt
import math

def l_system(schemat, n):
    if n == 0:
        return schemat
    new = ""
    for i in schemat:
        if i == 'F':
            new += 'F+F-F-F+F'
        elif i == '+':
            new += '+'
        elif i == '-':
            new += '-'
        else:
            raise Exception("Zly znak")
    return l_system(new, n-1)

def draw(schemat, n):
    x = 0
    y = 0
    angle = 0
    xlist = [0]
    ylist = [0]
    for i in l_system(schemat, n):
        if i == 'F':
            x += math.cos(math.radians(angle))
            y += math.sin(math.radians(angle))
            xlist.append(x)
            ylist.append(y)
        elif i == '+':
            angle += 90
        elif i == '-':
            angle -= 90
    plt.plot(xlist, ylist)
    plt.show()
    plt.close()


#1.2 Funkcję dokonującą przekształcenia punktu na płaszczyźnie według wzorów (ifs):
#x(t+1) = a*x(t) + b*y(t) + c
#y(t+1) = d*x(t) + e*y(t) + f
# Przykładowy zestaw współczynników a,b,c,d,e,f:
# ((0,0,0,0,0.16,0),(0.2,-0.26,0.23,0.22,1.6),(-0.15,0.28,0,0.26,0.24,0.44),(0.85,0.04,0,-0.04,0.85,1.6))
# Przy kolejnych przekształceniach określoną szóstkę współczynników wybieramy z prawdopodobieństwem 1%, 7%, 7%, 85%.
# Proszę zgłosić wyjątek jeżeli liczba zestawów współczynników jest różna od długości krotki z prawdopodobieństwami, suma prawdopodobieństw nie jest równa 1 lub któryś z zestawów współczynników ma długosć różną od 6.
# Wynik proszę narysować
#print("Zadanie 1.2")

import random

def ifs(punkt, wspolczynniki, prawdopodobienstwa, n):
    if len(wspolczynniki) != len(prawdopodobienstwa):
        raise Exception("Zly rozmiar")
    if sum(prawdopodobienstwa) != 1:
        raise Exception("Zly rozmiar")
    for i in wspolczynniki:
        if len(i) != 6:
            raise Exception("Zly rozmiar")
    if n == 0:
        return punkt
    los = random.random()
    for i in range(len(prawdopodobienstwa)):
        if los < prawdopodobienstwa[i]:
            wsp = wspolczynniki[i]
            break
        los -= prawdopodobienstwa[i]
    x = wsp[0]*punkt[0] + wsp[1]*punkt[1] + wsp[2]
    y = wsp[3]*punkt[0] + wsp[4]*punkt[1] + wsp[5]
    return ifs((x,y), wspolczynniki, prawdopodobienstwa, n-1)

def draw_ifs(punkt, wspolczynniki, prawdopodobienstwa, n):
    xlist = [punkt[0]]
    ylist = [punkt[1]]
    for i in range(n):
        punkt = ifs(punkt, wspolczynniki, prawdopodobienstwa, 1)
        xlist.append(punkt[0])
        ylist.append(punkt[1])
    plt.plot(xlist, ylist, 'o')
    plt.show()

draw_ifs((0,0), ((0,0,0,0,0.16,0),(0.2,-0.26,0,0.23,0.22,1.6),(-0.15,0.28,0,0.26,0.24,0.44),(0.85,0.04,0,-0.04,0.85,1.6)), (0.01,0.07,0.07,0.85), 10000)

#2 Funkcję sprawdzającą poprawność numeru PESEL
# Parametrami wejściowymi do funkcji są: Pesel, data urodzenia(datatime.date) oraz płeć
# Przykłady:
#02070803628, 8 lipca 1902, kobieta
#02270803624, 8 lipca 2002, kobieta
#02270812350, 8 lipca 2002, mężczyzna

#PESEL:
#1-2: ostatnie dwie cyfry roku urodzenia
#3-4: miesiąc urodzenia
#5-6: dzień urodzenia
#7-10: numer serii z oznaczeniem płci
#11: cyfra kontrolna
# Do numeru miesiąca dodawane są następujące wartości w zależności od roku:
# dla lat 1800-1899: 80
# dla lat 1900-1999: 0
# dla lat 2000-2099: 20
# dla lat 2100-2199: 40
# dla lat 2200-2299: 60

#Suma kontrolna: każdą pozycję numeru ewidencyjnego mnoży się przez odpowiednią wagę, są to kolejno: 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 i 1 i sumuje
# Wynik dzieli się przez modulo 10 i otrzymaną wartość należy odjąć od 10 i znów podzielić modulo 10.
# Otrzymana wartość powinna być taka sama jak ostatnia cyfra numeru PESEL, w przeciwnym razie numer jest błędny.
#print("Zadanie 2")
import datetime as data

def pesel(pesel, data, plec):
    if len(pesel) != 11:
        print("Niepoprawna dlugosc peselu")
        return False
    if int(pesel[4:6]) > 31:
        print("Niepoprawny dzien")
        return False
    if int(pesel[9]) % 2 == 0 and plec == "mezczyzna":
        print("Niepoprawna plec")
        return False
    if int(pesel[9]) % 2 == 1 and plec == "kobieta":
        print("Niepoprawna plec")
        return False
    if data.year > 1800 and data.year < 1899:
        add = 1800
        addmonth = 80
        if data.month != int(pesel[2:4]) - 80:
            print("Niepoprawny miesiac 1")
            return False
    if data.year > 1900 and data.year < 1999:
        add = 1900
        addmonth = 0
        if data.month != int(pesel[2:4]):
            print("Niepoprawny miesiac 1")
            return False
    if data.year > 2000 and data.year < 2099:
        add = 2000
        addmonth = 20
        if data.month != int(pesel[2:4]) - 20:
            print("Niepoprawny miesiac 1")
            return False
    if data.year > 2100 and data.year < 2199:
        add = 2100
        addmonth = 40
        if data.month != int(pesel[2:4]) - 40:
            print("Niepoprawny miesiac 1")
            return False
    if data.year > 2200 and data.year < 2299:
        add = 2200
        addmonth = 60
        if data.month != int(pesel[2:4]) - 60:
            print("Niepoprawny miesiac 1")
            return False
    if data.day != int(pesel[4:6]):
        print("Niepoprawny dzien 1")
        return False
    if data.month != (int(pesel[2:4]) - addmonth):
        print("Niepoprawny miesiac 1")
        return False
    if data.year != (int(pesel[0:2]) + add):
        print("Niepoprawny rok 1")
        return False
    suma = 0
    weight = [1, 3, 7, 9, 1, 3, 7, 9, 1, 3]
    for i in range(10):
        suma += int(pesel[i]) * weight[i]
    suma = (10 - suma % 10)%10
    if suma != int(pesel[10]):
        print("Niepoprawna suma kontrolna")
        return False
    print("Pesel poprawny")
    return True

    
pesel1 = "02070803628" #prawda
data1 = data.date(1902, 7, 8)
plec1 = "kobieta"
#check1 = pesel(pesel1, data1, plec1)
pesel2 = "02270803624" #prawda
data2 = data.date(2002, 7, 8)
plec2 = "kobieta"
#check2 = pesel(pesel2, data2, plec2)
pesel3 = "02270812350" #prawda
data3 = data.date(2002, 7, 8)
plec3 = "mężczyzna"
#check3 = pesel(pesel3, data3, plec3)
pesel4 = "02282204975" #falsz
data4 = data.date(2002, 8, 22)
plec4 = "mężczyzna"
#check4 = pesel(pesel4, data4, plec4)
#3 Funkcja zwracająca średni wiek osób, których daty urodzenia zapisane są w pliku daty.in
# Funkcja powinna móc działać w trybie 'restrykcyjnym' - po napotkaniu niepoprawnej daty/wpisu zgłoszenie wyjątku i przerwanie działania, oraz w trybie 'liberalnym' - po napotkaniu niepoprawnej daty/wpisu pominąć go i kontynuować działanie
# Linia w pliku jest poprawna, jeśli zawiera dzień, miesiąc i rok, które tworzą poprawną datę - zgodność liczby dni z miesiącem i rokiem (np. 29 lutego 2001 jest niepoprawne) 
# Rok przestępny: podzielny przez 4, niepodzielny przez 100, podzielny przez 400
#print("Zadanie 3")

def average_age1(file, mode):
    try:
        with open(file, "r") as f:
            lines = f.readlines()
            suma = 0
            count = 0
            date = []
            for line in lines:
                print(int(line[5:10]))
                try:
                    line = line.split()
                    date = data.date(int(line[6:10]), int(line[3:5]), int(line[0:2]))
                    suma += date.year
                    count += 1
                except:
                    if mode == "restrykcyjny":
                        raise Exception("Niepoprawna data restrykcyjny")
                    else:
                        print("Niepoprawna data liberalny")
            print("Sredni wiek: " + str(suma/count))
    except:
        print("Niepoprawna sciezka do pliku")

def average_age(file, mode):
        with open(file, "r") as f:
            lines = f.readlines()
            suma = 0
            count = 0
            for line in lines:
                line = line.split()
                if len(line) == 3:
                    if int(line[1])!=2:
                        if int(line[0]) <= 31 and int(line[1]) <= 12:
                            print("data poprawna 1",line[2])
                            suma += int(line[2])
                            count += 1
                        else:
                            if mode == "restrykcyjny":
                                print("Niepoprawna data restrykcyjny")
                                raise Exception("Niepoprawna data restrykcyjny")
                            else:
                                print("Niepoprawna data liberalny")
                    elif int(line[1]) == 2 and int(line[0]) > 29:
                        if mode == "restrykcyjny":
                            print("Niepoprawna data restrykcyjny")
                            raise Exception("Niepoprawna data restrykcyjny")
                        else:
                            print("Niepoprawna data liberalny")
                    elif int(line[0]) ==29 and int(line[1]) == 2:
                        if (int(line[2]) % 4 == 0 and int(line[2]) % 100 != 0) or int(line[2]) % 400 == 0:
                            print("data poprawna 3",line[2])
                            suma += int(line[2])
                            count += 1
                        else:
                            if mode == "restrykcyjny":
                                print("Niepoprawna data restrykcyjny")
                                raise Exception("Niepoprawna data restrykcyjny")
                            else:
                                print("Niepoprawna data liberalny")
                    elif int(line[0])<29 and int(line[1]) == 2:
                        print("data poprawna 2",line[2])
                        suma += int(line[2])
                        count += 1
            print("Sredni wiek: " + str(suma/count))

#average_age("daty.in", "liberalny")