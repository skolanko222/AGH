k = [[]]*10 
k[3].append(1) # wszystkie listy sa tym samym miejscem w pamieci
print(k)

#####

k = [[] for _ in range(10)] # tu jest ok
k[3].append(1)
print(k)

#####

k[3].append([1,2,3])
print("append", k)

k[3].extend([1,2,3])
print("extend",k) # rozszerza o elementy listy


k[3].extend('text')
print("extend 2",k) # rozpakowanie stringa i dodatnie po jednym znaku

####

k = tuple(range(10,0,-1)) #rozmiar = 30-20
print(k)

k = tuple(range(10,0,1)) 

####

k = [i for i in range(0,20,2)]
for i in k:
	i*=2 # nie modyfikuje
	print(i,end=', ')
print('\nk2',k)

for i in range(len(k)):
	k[i]*=2 # modyfikuje
	print(k[i],end=', ')
print('\nk3',k)

#### enumerate

k = [i for i in range(0,20,3)]

for i, j in enumerate(k):
	k[i] = 1 if j > 0 else -1

print('k4',k)

####

for i in k:
	if not i%2:
		break
else:
	print('2222')

####

n = [1 if i>0 else -1 for i in k]
print("n:",n)

####

l = [[(i,j) for j in range(3)] for i in range(3)]
print("l",l)

####

p = [(23,12),(43,67),(34,12),(43,90),]
c = p[:]
p.sort(key = lambda x : x[1],reverse=True) #
print(p)

####

c = p[:]
for i,j in sorted(c):
	print(i,j, end = '|')
print('\n',c)

####
