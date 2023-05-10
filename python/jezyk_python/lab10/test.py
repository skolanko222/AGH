class Wektor3D:
	def __init__(self, x, y, z):
		self.x = x
		self.y = y
		self.z = z
	def __add__(self, other):
		return Wektor3D(self.x + other.x, self.y + other.y, self.z + other.z)
	def __sub__(self, other):
		return Wektor3D(self.x - other.x, self.y - other.y, self.z - other.z)
	def __mul__(self, value):
		return Wektor3D(self.x * value, self.y * value, self.z * value)
	def __rmul__(self, value):
		return Wektor3D(self.x * value, self.y * value, self.z * value)
	def __str__(self):
		return f"({self.x}, {self.y}, {self.z})"
	def vec_len(self):
		return (self.x**2 + self.y**2 + self.z**2)**0.5
	def iloczyn_skalarny(self, other):
		return self.x*other.x + self.y*other.y + self.z*other.z
	def iloczyn_wektorowy(self, other):
		return Wektor3D(self.y*other.z - self.z*other.y, self.z*other.x - self.x*other.z, self.x*other.y - self.y*other.x)
	def iloczyn_mieszany(self, other1, other2):
		return self.iloczyn_skalarny(other1.iloczyn_wektorowy(other2))

	
w1 = Wektor3D(1, 2, 3)
w2 = Wektor3D(4, 5, 6)
print(w1 + w2)
print(w1*2)
