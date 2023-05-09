'''łańcuch dokumentacji modułu'''
import datetime

def zad2(pesel, data, plec):
	'''łańcuch doc funkcji zad2'''
	try:
		x = datetime.datetime(*data)
	except TypeError:
		x = data
	
	try:
		arr = {}
		arr[0] = [int(pesel[0]),int(pesel[1]),]
		arr[1] = [int(pesel[2]),int(pesel[3]),]
		arr[2] = [int(pesel[4]),int(pesel[5]),]
		arr[3] = [int(pesel[6]),int(pesel[7]),int(pesel[8]),]

	except:
		pass
	# 0-1

	if x.year % 10 == arr[0][0]*10 + arr[0][1]:
		print("rok ok")
	# 2-3
	if x.year <= 1899:
		if arr[1][0]*10 + arr[1][1] == x.month + 80:
			print("miesiac ok")
	if x.year <= 1999 and x.year >= 1900:
		if arr[1][0]*10 + arr[1][1] == x.month:
			print("miesiac ok")
	if x.year <= 2099 and x.year >= 2000:
		if arr[1][0]*10 + arr[1][1] == x.month + 20:
			print("miesiac ok")
	if  x.year <= 2199 and x.year >= 2100:
		if arr[1][0]*10 + arr[1][1] == x.month + 40:
			print("miesiac ok")
	if  x.year <= 2299 and x.year >= 220:
		if arr[1][0]*10 + arr[1][1] == x.month + 60:
			print("miesiac ok")
>>>>>>> fe17cc0e9a49aa6086ce250c7751e398dac47f42
