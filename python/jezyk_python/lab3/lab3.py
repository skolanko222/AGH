import sys

# 1 Proszę utworzyć string składający się z elementów listy argv z wyłączeniem nazwy programu.
#  Jeżeli program został uruchomiony bez podania parametrów proszę wypisać na ekran komunikat informujący o właściwym sposobie uruchomienia programu (1p)
print('zad1'.center(10,'-'))
if len(sys.argv) > 1:
	string = ''.join(sys.argv[1:])
else:
	sys.exit()


print(string)

#Na podstawie wcześniej utworzonego stringa proszę utworzyć cztery listy: zawierającą małe litery, zawierającą duże litery, zawierającą cyfry oraz zawierającą wszystko co nie jest literą (2p)
print('zad2'.center(10,'-'))
a = [i for i in string if i.islower()]
b = [i for i in string if i.isnumeric()]
c = [i for i in string if i.isupper()]
d = [i for i in string if not i.isalpha() and not i.isnumeric()]

print(a,b,c,d)

#Na podstawie utworzonej listy zawierającej małe litery proszę utworzyć listę małych liter bez powtórzeń (bez użycia typu set). 
# Następnie proszę utworzyć nową listę, w której każdy element jest dwuelementową krotką (litera, krotność jej wystąpienia w liście oryginalnej), proszę wykorzystać konstrukcję listy składanej (2p)
print('zad3'.center(10,'-'))
bez_powtorzen = []

for x in a:
	if x not in bez_powtorzen:
		bez_powtorzen.append(x)
print(bez_powtorzen)

lista_krotek = [(i,a.count(i)) for i in bez_powtorzen]
print(lista_krotek)

#Otrzymaną w powyższym punkcie listę proszę wyświetlić w kolejności od najwyższej krotności (bez sortowania listy oryginalnej) (1p)
print('zad4'.center(10,'-'))
print(sorted(lista_krotek, key = lambda x : x[1], reverse = True))


# Proszę utworzyć listę dwuelementowych krotek, w których pierwszy element jest liczbą pobraną z listy cyfr, drugi natomiast wartością funkcji liniowej ax+b dla danej liczby; 
# wartości współczynników proszę ustalić w następujący sposób: a równa się liczbie samogłosek w stringu z punktu pierwszego, a b - liczbie spółgłosek tamże (2p)
print('zad5'.center(10,'-'))
samogloski = "AEIOUYaeiouy"

ilosc_samoglosek = sum(string.count(i) for i in samogloski)
ilosc_spolglosek = len(a) + len(c) - ilosc_samoglosek
print(ilosc_samoglosek,ilosc_spolglosek)

lista_krotek_2 = [(int(i),int(i)*ilosc_samoglosek + ilosc_spolglosek) for i in b]
print(lista_krotek_2)

#Proszę obliczyć wartości parametrów prostej korzystając z metody najmniejszych kwadratów (2p):
print('zad6'.center(10,'-'))
#lista_krotek_2=[(1,1),(2,2),(3,3)]
if b:
	x_s = sum(i[0] for i in lista_krotek_2)/len(lista_krotek_2)
	D = sum((i[0]-x_s)**2 for i in lista_krotek_2)
	y_s = sum(i[1] for i in lista_krotek_2)/len(lista_krotek_2)
	a = sum(j*(i - x_s )for i,j in lista_krotek_2)/D
	b=y_s -a*x_s

	print(f"{a=},{b=},{D=}")
