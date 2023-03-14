"""k = (2,)
print(k)


kr = (1,2.,[232,23,23], {'klucz':213},)
print(kr, len(kr))

kr[-1]['klucz'] = 1
print(kr, len(kr))

arr = [2,2.23,'9',(3,5)]

arr[-1] = 2
print(arr, arr[len(arr) -1])"""


import copy

k = [0,1,443,23,435,[63,1],45,345]

c = copy.deepcopy(k) # KUPIUJE LISTY W SRODKU!!

c[0] = 1
k[-3][0] = 2137

print(k,c)
print(id(k),id(c))

k[1:4] = [[7,8,],]
print(k)




