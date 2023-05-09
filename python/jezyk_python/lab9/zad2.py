import datetime
class RokError(Exception):
	pass
class MiesiacError(Exception):
	pass
class DzienError(Exception):
	pass
class PlecError(Exception):
	pass

def zad(pesel, data, plec):
	'''lancuch doc funkcji zad2'''
	x = data
	arr = {}
	arr[0] = [int(pesel[0]),int(pesel[1]),]
	arr[1] = [int(pesel[2]),int(pesel[3]),]
	arr[2] = [int(pesel[4]),int(pesel[5]),]
	arr[3] = [int(pesel[6]),int(pesel[7]),int(pesel[8]),]
	# 0-1

	if x.year % 10 != arr[0][0]*10 + arr[0][1]:
		raise RokError
	# 2-3
	if x.year <= 1899:
		if arr[1][0]*10 + arr[1][1] != x.month + 80:
			raise MiesiacError
	if x.year <= 1999 and x.year >= 1900:
		if arr[1][0]*10 + arr[1][1] != x.month:
			raise MiesiacError
	if x.year <= 2099 and x.year >= 2000:
		if arr[1][0]*10 + arr[1][1] != x.month + 20:
			raise MiesiacError
	if  x.year <= 2199 and x.year >= 2100:
		if arr[1][0]*10 + arr[1][1] != x.month + 40:
			raise MiesiacError
	if  x.year <= 2299 and x.year >= 2200:
		if arr[1][0]*10 + arr[1][1] != x.month + 60:
			raise MiesiacError
		
	# 4-5
	if arr[2][0]*10 + arr[2][1] != x.day:
		raise DzienError

	# plec
	#print(arr[3][0]*100 + arr[3][1]*10 + arr[3][2])
	if arr[3][0]*100 + arr[3][1]*10 + arr[3][2] % 2 == 0 and plec != "kobieta":
		raise PlecError
	if arr[3][0]*100 + arr[3][1]*10 + arr[3][2] % 2 == 1 and plec != "mezczyzna":
		raise PlecError
