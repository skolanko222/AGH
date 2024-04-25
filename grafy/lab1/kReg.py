@staticmethod
def generateKRegularGraph(n, k): # n - number of vertices, k - degree
	if n <= k:
		raise Exception("n must be greater than k")
	if k * n % 2 != 0:
		raise Exception("k * n must be even")

	
	# degree sequence
	degreeSequence = [[i, k] for i in range(n)] # i - vertex, k - degree of vertex
	adjList = [[] for i in degreeSequence]
	# print(degreeSequence)
	

	while True:
		# check if all degrees in degreeSequence are equal to k
		if all(i[1] == 0 for i in degreeSequence):
			break
		for i in range(1, degreeSequence[0][1] + 1):
			degreeSequence[i][1] -= 1
			# add an edge between vertices a and b
			a = degreeSequence[0][0]
			b = degreeSequence[i][0]
			adjList[a].append(b)    
			adjList[b].append(a)        
		
		degreeSequence[0][1] = 0
		degreeSequence.sort(reverse=True, key=lambda x: x[1]) # sort by degree
	g = MyGraph(adjList, 1)
	# g.randomizeGraph(1)
	return g