class RangeError(Exception):
    pass

def main():
    print("Dostepne dzialania:")
    print("1. Dodawanie")
    print("2. Mnozenie")
    print("3. Dzielenie")
    print("4. Odejmowanie")
    print("Podaj 1 liczbe")
    x = input()
    if x[0] == '-':
        if x.lstrip("-").isdigit() != True:
            raise TypeError("Pierwszy argument nie jest liczba!")
    else:
        if x.isdigit() != True:
            raise TypeError("Pierwszy argument nie jest liczba!")

    print("Podaj 2 liczbe")
    y = input()
    if y[0] == '-':
        if y.lstrip("-").isdigit() != True :
            raise TypeError("Drugi argument nie jest liczba!")
    else:
        if y.isdigit() != True:
            raise TypeError("Pierwszy argument nie jest liczba!")

    print("Dzialanie")
    z = input()

    if y.isdigit() != True :
        raise TypeError("Trzeci argument nie jest liczba!")

    if int(z) not in range(1,5):
       raise ValueError("Dzialanie moze byc liczba mniedzy 1 a 4")
   
    operation(x,y,z)


def add(x,y):
    return float(x) + float(y)

def div(x,y):
    if int(y) == 0:
        raise ValueError("Dzielenie przez 0!")
    return float(x)/float(y)

def sub(x,y):
    return float(x) - float(y)

def multiply(x,y):
    return float(x)*float(y)

def operation(x,y,z):
    if int(z) == 1:
        print("Wynik: ",add(x,y))
    if int(z) == 2:
        print("Wynik: ",multiply(x,y))
    if int(z) == 3:
        print("Wynik: ",div(x,y))
    if int(z) == 4:
        print("Wynik: ",sub(x,y))

if __name__ == "__main__":
    main()
