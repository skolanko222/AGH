import datetime

if __name__ == '__main__':
	import test
	print(test.__doc__)
	data = datetime.datetime(*(1902,7,8))
	print(test.zad2.__doc__)
	test.zad2("02070803628",data,"k")
	