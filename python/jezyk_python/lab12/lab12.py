# zad1
class Point:
	def __init__(self):
		self.x = 0
		self.y = 0

	def print(self):
		print(f'({self.x=}, {self.y=})')

def check_val(max_a,max_b):
	def fz(pf):
		def fw(p,a,b):
			if p.x + a > max_a or p.y + b > max_b:
				raise ValueError("nie z przedzialu")
			return pf(p,a,b)
		return fw
	return fz

# zad2
@check_val(10,10)
def dodaj(obj, x, y):
	obj.x += x
	obj.y += y
@check_val(10,50)
def odejmij(obj, x, y):
	obj.x -= x
	obj.y -= y

# zad3
class Fig:
	@staticmethod
	def obwod(*a):
		return sum(((a[i].x - a[i + 1].x)**2 + (a[i].y - a[i + 1].y)**2)**0.5 for i in range(-1,len(a)-1))

	@staticmethod
	def pole(*a):
		p = Fig.obwod(*a)
		boki = [((a[i].x - a[i + 1].x)**2 + (a[i].y - a[i + 1].y)**2)**0.5 for i in range(-1,len(a)-1)]
		if len(a) == 3:
			return (p*(p-boki[0])*(p-boki[1])*(p-boki[2]))**0.5
		if len(a) == 4:
			return (p*(p-boki[0])*(p-boki[1])*(p-boki[2]))**0.5
		
# zad4
class Counter:
	cnt = {}
	def __init__(self,fun):
		self.fun = fun
		Counter.cnt[fun.__name__] = 0
	def __call__(self,*args):
		Counter.cnt[self.fun.__name__] += 1
		return self.fun(*args)
	
	@staticmethod
	def getCounter():
		return Counter.cnt
		
@Counter
def test():
	pass
@Counter
def test2():
	pass


if __name__ == '__main__':
    # zad1
	a = Point()
	b = Point()
	c = Point()
	d = Point()
	# zad2

	dodaj(a,0,0)
	dodaj(b,1,0)
	dodaj(c,1,1)
	dodaj(d,0,1)

	# zad3
	print("obwod kwadratu", Fig.obwod(a,b,c,d))
	print("pole trojkata", Fig.pole(a,b,c))

	# zad3
	test()
	test()

	test2()
	test2()
	test2()

	print(Counter.getCounter())