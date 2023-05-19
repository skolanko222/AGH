# zad1
import collections
import json
import dataclasses
import os
class Stos:
	def __init__(self, *obj):
		self.data = []
		if len(obj) == 1:
			match obj[0]:
				case Stos() as s:
					print("case stos")
					for i in s.data:
						self.data.append(i)
				case list() as l:
					print("case list")
					for i in l:
						self.data.append(i)
		elif len(obj) > 1:
			print("pojedyncze elem")
			for i in obj:
				self.data.append(i)

	def append(self,a):
		self.data.append(a)

	def __repr__(self):
		return str(self.data)
		
class SortedStos(Stos):
	def __init__(self,*obj):
		super().__init__(*obj)
		cnt = collections.Counter(type(i) for i in self.data)
		#print(cnt.most_common(1)[0][0])
		self.dataCommon = [i for i in self.data if type(i) == cnt.most_common(1)[0][0]]
		self.dataCommon.sort()

	def __repr__(self):
		return str(self.dataCommon)

	def appendSorted(self,a):
		if a > self.dataCommon[-1]:
			self.dataCommon.append(a)
		else:
			print("nie mozna dodac elem!")


# zad2

@dataclasses.dataclass
class Pracownik:
	nazwisko : str
	wiek : int
	wyksztalcenie : str

@dataclasses.dataclass
class OfertaPracy:
	opis : str
	wiek : int
	wyksztalcenie : str

class EnhancedJSONEncoder(json.JSONEncoder):
    def default(self, o):
        if dataclasses.is_dataclass(o):
            return dataclasses.asdict(o)
        return super().default(o)

def readJson(filename):
	if os.path.isfile(filename):
		with open(filename) as plik:
			data = json.load(plik)[0]
		print(data)

def saveJson(filename,arr):
	if os.path.isfile(filename):
		with open(filename,"w") as plik:
			json.dump(arr,plik,cls=EnhancedJSONEncoder)



if __name__ == '__main__':
	# zad1
	s = Stos(1,2,3,4)
	f = Stos([0,0,0,0])
	g = Stos(s)
	g.append(23)

	print(s)
	print(f)
	print(g)

	s2 = SortedStos(1,10,3,4,5,'a','b')
	s2.appendSorted(111)
	s2.appendSorted(11)
	print(s2)

	# zad2
	a = Pracownik("name1",20,"wyk1")
	b = Pracownik("name2",22,"wyk2")
	readJson("test.json")
	saveJson("test1.json",[a,b])