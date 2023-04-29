#1 Proszę napisać funkcję, która pozwoli na wypisanie n początkowych wierszy pliku,
# n końcowych wierszy pliku, co n-tego wiersza pliku, n-tego słowa ze wszystkich wierszy i n-tego znaku ze wszystkich wierszy.
# Nazwę pliku oraz n przekazujemy jako parametr do funkcji. Kazdy podpunkt to jedna linia kodu.
print("Zadanie 1")

def nfirstlines(filename, n):
    return open(filename).readlines()[:n]

def nlastlines(filename, n):
    return open(filename).readlines()[-n:]

def nlines(filename, n):
    return open(filename).readlines()[::n]

def nwords(filename, n):
    return [line.split()[n] for line in open(filename).readlines()]

def nchars(filename, n):
    return [line[n] for line in open(filename).readlines()]

#FILE = "Lab8.txt"
#print(nfirstlines(FILE, 5))
#print(nlastlines(FILE, 3))
##print(nlines(FILE, 3))
#print(nwords(FILE, 1))
#print(nchars(FILE, 2))

#2 Odczytujemy wartości ze wszystkich plików, których nazwy rozpoczynają się od data i kończą na in w katalogu bieżącym.
# Na wyjściu proszę utworzyć jeden plik z trzema kolumnami.
# pierwsza kolumna to numer wiersza, druga kolumna to uśredniona wartość z danego wiersza ze wszystkich plików,
# trzecia kolumna to odchylenie standardowe z danego wiersza ze wszystkich plików (numpy.std).
print("Zadanie 2")
import glob
from numpy import std,mean
def readfiles():
    files = glob.glob("data*.in")
    data = []
    for file in files:
        data.append([float(line) for line in open(file).readlines()])
    print(data)
    return data

def writefile(data):
    f = open("res2.out", "w")
    for i in range(len(data[0])):
        f.write(str(i) + " ")
        f.write(str(mean([data[j][i] for j in range(len(data))])) + " ")
        f.write(str(std([data[j][i] for j in range(len(data))])) + "\n")

data = readfiles()
writefile(data)
#3 Proszę napisać funkcję tworzącą plik z instrukcjami pozwalającymi na wygenerowanie wykresu plików j.w +
# wynikowego (łącznie z odchyleniem standardowym), proszę skorzystać z potrójnego cudzysłowa.
print("Zadanie 3")

#4 Pliki o nazwach rok.in zawierają informacje o pozycji na liście rankingowej pewnych osób, w kolejnych latach.
# Proszę utworzyć zbiorczy plik, w którym w pierwszej kolumnie znajdzie się "nazwisko",
# kolejne kolumny będą odpowiadały pozycji danej osoby na liście rankingowej w kolejnych latach, od 2000 d0 2020.
print("Zadanie 4")

def readfiles():
    files = glob.glob("20*.txt")
    data = []
    for file in files:
        data.append([line.split() for line in open(file).readlines()])
    return data
def writefile(data):
    f = open("res4.out", "w")
    f.write("Nazwisko")
    for file in glob.glob("20*.txt"):
        f.write(" " + file[:4])
    f.write("\n")
    max = 0
    for file in glob.glob("20*.txt"):
        if max < len(open(file).readlines()):
            max = len(open(file).readlines())
            index = glob.glob("20*.txt").index(file)
    for i in range(max):
        f.write(data[index][i][0] + "     ")
        for j in range(len(data)):
            if i < len(data[j]):
                f.write("   " + data[j][i][1])
            else:
                f.write("   -")
        f.write("\n")

data = readfiles()
writefile(data)
#5 Proszę sporządzić histogram słów rozpoczynających się na daną literę alfabetu ze wszystkich plików pasujących do wzorca w katalogu bieżącym.
# ,opcje wyświetlania: sortowanie alfabetyczne bądź po liczbie słów
print("Zadanie 5")
import matplotlib.pyplot as plt
import numpy as np

files = glob.glob("zad*.in")
data = []
for file in files:
    data.append([line.split() for line in open(file).readlines()])
print(data)
n=1
x = [chr(i) for i in range(97, 123)]
y = []
for i in range(len(x)):
    y.append(0)
    for j in range(len(data)):
        for k in range(len(data[j][0])):
            print(x[i])
            print(data[j][0][k])
            if data[j][0][k][0].lower() == x[i]:
                y[i] += 1
# jesli n==1 to posortowac x malejaco w zaleznosci od wartosci y(x)
if n==1:
    for i in range(len(x)):
        for j in range(i+1, len(x)):
            if y[i] < y[j]:
                y[i], y[j] = y[j], y[i]
                x[i], x[j] = x[j], x[i]
plt.bar(x, y)
plt.xlabel("Litera alfabetu")
plt.ylabel("Liczba wystąpień")
#plt.show()
plt.savefig("res.pdf")

