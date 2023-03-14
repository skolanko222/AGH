#Korzystając z pętli for proszę usunąć wszystkie wystąpienia określonej wartości z listy (1p)

a = [1,2,3,4,5,6,3]
wartosc = 3
for i in range(len(a)-1):
	if a[i] == wartosc: 
		a.pop(i)

print("zad1",a)

#j.w. ale korzystając z pętli while (1p)

a = [1,2,3,4,5,6,3]
i = 0
while i < len(a):
	if a[i] == wartosc: 
		a.pop(i)
	i+=1
print("zad2",a)

#Korzystając z pętli for oraz funkcji range proszę wypisać co drugi element listy począwszy od elementu o indeksie 1 (bez instrukcji warunkowej) (0.5p)
a = [1,2,3,4,5,6,3]
print('zad3', end = ' ')
for i in range(1,len(a),2):
	print(a[i], end = ' ')

# j.w. ale bez range (0.5p)
a = [1,2,3,4,5,6,3]
b = [ i for i in a[1::2]]
print('\nzad4',b)

#Korzystając z pętli for oraz funkcji range proszę wypisać co drugi element listy od końca (bez instrukcji warunkowej) (1p)
print('zad5',end = ' ')
for i in range(len(a) - 1,-1,-2):
	print(a[i],end = ' ')

#j.w. ale bez range (1p)
a = [1,2,3,4,5,6,3]
print('\nzad6',end = ' ')
b = a[len(a) - 1::-2]
print(b,end = ' ')

#Proszę utworzyć nową listę, której elementami są krotki (indeks, element) na podstawie istniejącej listy <- lista składana (1p)
b = [2,1,3,7,4,2,6]
arr = [(i,b[i]) for i in range(len(b))]
print('\nzad7', arr)

#Proszę posortować listę z poprzedniego punktu wg drugiego elementu krotek (1p)
def fun(x):
	return x[1]
arr.sort(key = fun)
print("zad8",arr)

#Proszę utworzyć nową listę, której elementami są krotki (indeks, element) na podstawie istniejącej listy, przy czym dodajemy krotkę tylko, jeśli wartość pobrana z listy jest wartością parzystą <- lista składana (1p)
b = [2,1,3,7,4,2,6]
arr = [(i,b[i]) for i in range(len(b)) if b[i] % 2 == 0]
print("zad9",arr)

#Proszę utworzyć nową listę, której elementami są krotki (indeks, element) lub (element, indeks) na podstawie istniejącej listy, tak, aby pierwszy element krotki był mniejszy od drugiego <- lista składana (1p)
arr = [(i,j) if i < j else (j,i) for i,j in enumerate(b)]
print("zad10",arr)

#Proszę utworzyć listę 2D (lista składana) wypełnioną zerami oraz jedynkami, przy czym jedynki występują:
# w kwadracie o boku mniejszym od rozmiaru listy na jej "środku" (0.2p)
# na przekątnej od lewego górnego rogu do prawego dolnego (0.2p)
# na przekątnej od prawego górnego rogu do lewego dolnego (0.2p)
# na obu przekątnych (0.2p)
# w szachownicę (0.2p)
def print_arr(arr,a):
	print(a)
	for i in range(len(arr)):
		print(arr[i])
#a
kwadrat_duzy = 10
kwadrat_maly = 7

temp = kwadrat_duzy - kwadrat_maly -1

arr = [[0]*kwadrat_duzy for _ in range(kwadrat_duzy)]
for i in arr[1:kwadrat_duzy-temp]:
	for j in range(1,kwadrat_duzy-temp):
		i[j] = 1
print_arr(arr,"podpunkt a")

#b
arr = [[1 if i==j else 0 for j in range(kwadrat_duzy)] for i in range(kwadrat_duzy)]

print_arr(arr,"podpunkt b")
#c
arr = [[1 if i==kwadrat_duzy-j-1 else 0 for j in range(kwadrat_duzy)] for i in range(kwadrat_duzy)]

print_arr(arr,"podpunkt c")
#d
arr = [[1 if i==kwadrat_duzy-j-1 or i==j else 0 for j in range(kwadrat_duzy)] for i in range(kwadrat_duzy)]

print_arr(arr,"podpunkt d")

#e

arr = [[j%2 if i%2 else (j+1)%2 for j in range(kwadrat_duzy)] for i in range(kwadrat_duzy)]

print_arr(arr,"podpunkt e")