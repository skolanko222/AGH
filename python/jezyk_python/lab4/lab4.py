import random
import string
# Proszę utworzyć k-elementową listę całkowitych wartości losowych z przedziału [0,5k).
# Proszę sprawdzić ile elementów pozostaje na swoim miejscu po losowym przemieszaniu listy, mieszanie proszę wykonać 100 razy a wyniki zapisywać w słowniku (2p)

k = 5
k1 = [random.randint(1,k*1000 -1) for i in range(0,k+1)]
k2 = k1.copy()

s = dict.fromkeys(range(k+1),0)
for i in range(100):
	random.shuffle(k1)
	temp = sum(1 for j in range(k) if k1[j] != k2[j])
	s[temp]+=1
        

print("zad1",k2)
print(k1)
print(s)


# Proszę utworzyć losowy string o długości k zawierający tylko małe litery, pomiędzy poszczególne litery proszę wstawić kropkę (1p)
k = 10

string = '.'.join(random.choices(string.ascii_lowercase,k=k))
print("zad2:",string)

# Proszę utworzyć listę stu całkowitych wartości losowych z przedziału [0,20). Następnie na jej podstawie proszę utworzyć słownik, w którym klucze są liczbami z listy, a wartościami lista ich indeksów.
# w rozwiązaniu proszę wykorzystać metodę setdefault i funkcjię enumerate (1p)
# w rozwiązaniu proszę wykorzystać metody setdefault i index (1.5p)

#a
k1 = [random.randint(0,19) for i in range(100)]
s1 = {}

for i,j in enumerate(k1):
	s1.setdefault(j,[]).append(i)

print("zad3",s1)
k1 = [random.randint(0,19) for i in range(100)]
s2 = {}

#b

for i in k1:
	s2.setdefault(i,[]).append(k1.index(i,s2[i][-1]+1 if s2[i] else 0))
print(s2)	


#Proszę sprawdzić ile spośród 1000 losowych wartości całkowitych składających się z n cyfr, gdzie n jest z przedziału [3,6], jest liczbami palindromowymi. Wynik proszę zapisać w słowniku - jedna linijka (2.5p)




#Proszę utworzyć dwa słowniki o rozmiarze 10, w których kluczami są kolejne liczby naturalne, a wartościami liczby losowe z przedziału [1,100). Następnie w obu słownikach proszę zamienić miejscami klucze z wartościami.
#Na podstawie tak otrzymanych słowników proszę utworzyć nowy słownik, w którym klucze są kluczami występującymi jednocześnie w obu wcześniej utworzonych słownikach, wartościami natomiast są dwuelementowe krotki wartości związanych z danym kluczem w słownikach oryginalnych  (2p)

s1 = {i:random.randint(1,100) for i in range(100)}
s2 = {i:random.randint(1,100) for i in range(100)}

s1 = {j:i for i,j in s1.items()}
s2 = {j:i for i,j in s1.items()}

print('\n')
print("zad5",s1)
print(s2)

s3 = {}

for i,j in s1.items():
	for k,l in s2.items():
		if i == l:
			s3 = {i:(j,k)}

print("\ns3:",s3)