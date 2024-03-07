import numpy as np
import networkx as nx

class GraphRep:
	__n = 0		 # number of vertices
	__k = 0		 # number of edges
	__graph = [] # graph representation

	def __init__(self, n = 0, k = 0, graph = []):
		self.__n = n
		self.__k = k
		self.__graph = graph

	def loadMatrix(self, filename):
		# exampple matrix:
		# 0 1 0 0 1 1 0 0 0 0 0 0
		# 1 0 1 0 0 1 0 0 0 0 0 0
		# 0 1 0 1 1 0 0 0 0 0 0 1
		# 0 0 1 0 0 0 0 1 1 0 1 0
		# 1 0 1 0 0 0 1 0 1 0 0 0
		# 1 1 0 0 0 0 1 0 0 0 0 0
		# 0 0 0 0 1 1 0 1 0 0 0 0
		# 0 0 0 1 0 0 1 0 1 0 0 1
		# 0 0 0 1 1 0 0 1 0 1 0 0
		# 0 0 0 0 0 0 0 0 1 0 0 0
		# 0 0 0 1 0 0 0 0 0 0 0 0
		# 0 0 1 0 0 0 0 1 0 0 0 0
		
		with open(filename, 'r') as f:
			lines = f.readlines()
			self.__n = len(lines)
			self.__graph = np.zeros((self.__n, self.__n), dtype = int)

			try:
				for i in range(self.__n):
					if i not in [0, 1]:
						raise ValueError("Wrong format of graph file: " + filename)
					self.__graph[i] = list(map(int, lines[i].split()))
				self.__k = np.sum(self.__graph) // 2
			except ValueError:
				self.__n = 0
				self.__k = 0
				self.__graph = []
				raise
			except IndexError:
				self.__n = 0
				self.__k = 0
				self.__graph = []
				raise ValueError("Wrong file format, index error: " + filename)

	def loadList(self, filename):
		# example list:
		# 0. 3 8
		# 1. 2 5 6
		# 2. 1 3 6
		# 3. 2 4 5 12
		# 4. 3 8 9 11
		# 5. 1 3 7 9
		# 6. 1 2 7
		# 7. 5 6 8
		# 8. 4 7 9 12
		# 9. 4 5 8 10
		# 10. 9
		# 11. 4

		# convert list to matrix

		with open(filename, 'r') as f:	
			lines = f.readlines()
			# TODO
			try:
				pass
			except ValueError:
				self.__n = 0
				self.__k = 0
				self.__graph = []
				raise
			except:
				self.__n = 0
				self.__k = 0
				self.__graph = []
				raise ValueError("Wrong format of graph file: " + filename)	