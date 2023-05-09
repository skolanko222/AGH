
# Algorytm Luhna - cyfry w numerze karty indeksujemy od 15 (skrajna lewa) do 0 (skrajna prawa), indeksom parzystym nadajemy wagę jeden, 
# a nieparzystym dwa, przy czym wartości na nieparzystych indeksach podwajamy, jeśli otrzymana liczba jest większa od 10 sumujemy jej cyfry. 
# W numerze karty zastępujemy odpowiednio cyfry i przemnażamy je przez wagi, a następnie sumujemy. 
# Jeżeli otrzymana wartość jest podzielna bez reszty przez 10 uznajemy numer karty za poprawny. 
# Wyjątek zgłaszamy w przypadku kiedy parametr przekazany do funkcji nie składa się z samych cyfr,
# ma niepoprawną długość lub otrzymana suma kontrolna jest niepoprawna.
# Przykłady do testów : 924803, 1235567898765437, 1234567891234564, 1234567891234563 
class DlugosNr(Exception):
	pass
class BlednyKod(Exception):
	pass
class NieNumer(Exception):
	pass

def zad(kod):
	'''lancuch doc funkcji zad1'''
	if not kod.isnumeric():
		raise NieNumer
	if len(kod) != 16:
		raise DlugosNr
	
	dic = {i:int(j) if i%2==0 else 2*int(j) if 2*int(j)<10 else 1+(2*int(j))%10 for i,j in zip(range(15,-1, -1),kod)}
	suma = 0
	for i,j in dic.items():
		if i%2 == 0:
			suma+= j
		else:
			suma+= j*2
	
	if suma%10 != 0:
		raise BlednyKod
