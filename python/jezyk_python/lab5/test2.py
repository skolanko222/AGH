import random
def fun(a,b):
    for i, el in enumerate(b):
        b[i] = el % a

lst = random.choices(range(10), k = 5)

print(lst)
fun(2,lst)

print(lst)
