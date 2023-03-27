s={3:4}

w=s.setdefault(4,5)

k=s.setdefault(7,'a')
print(k)
k=s.setdefault(8,[]).append(2)


print(s)