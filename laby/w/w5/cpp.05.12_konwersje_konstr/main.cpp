#include <iostream>
#include <string>

class Frac {
public:
	friend Frac multi(const Frac& a, const Frac& b);
	
	Frac() : _l(0), _m(1) {}
	Frac(int l, int m) : _l(l), _m(m) {}

	//konstruktor służący jako konwerter z liczby typu int
	Frac(int l) : _l(l), _m(1) {
		std::cout << "Dziala konstruktor konwertujacy." << std::endl; 
	}
	
	
	void print() { 
		std::cout << _l << "/" << _m << std::endl; 
	}

private:
	int _l;
	int _m;
};

Frac multi(const Frac& a, const Frac& b) {
	Frac tmp;
	tmp._l = a._l * b._l;
	tmp._m = a._m * b._m;
	return tmp;
}

int main() {
	Frac aFraction;
	Frac bFraction(1, 2);
	
	//wykonujemy mno¿enie obiektu klasy Frac przez liczbę typu int - konwersja jest potrzebna
	aFraction = multi(bFraction, 1);
	aFraction.print();

	//kompilator rozumie to tak:
	aFraction = multi(bFraction, Frac(1));
	aFraction.print();
}
