#include <iostream>
#include <string>

class Frac
{
public:
	friend Frac multi(const Frac& a, const Frac& b);
	
	Frac() : _l(0), _m(1)	{}
	Frac(int l, int m) : _l(l), _m(m)	{}

	//konstruktor który nie może służyć jako konwerter z liczby typu int
	explicit Frac(int l) : _l(l), _m(1) {
		std::cout << "Dziala konstruktor jednoargumentowy." << std::endl;
	}
	
	void print() { 
		std::cout << _l << "/" << _m << std::endl; 
	}

private:
	int _l;
	int _m;
};

Frac multi(const Frac& a, const Frac& b)
{
	Frac tmp;
	tmp._l = a._l * b._l;
	tmp._m = a._m * b._m;
	return tmp;
}

int main()
{
	int n = 1;
	
	Frac aFraction;
	Frac bFraction(1, 2);
	
	//niemożliwe wykonanie automatycznej konwersji
	// aFraction = multi(bFraction, n);

	//ale możliwe wywołanie konstruktora jednoargumentowego
	aFraction = multi(bFraction, Frac(n));
	aFraction.print();

	//ale mo¿liwa jest jawa konwersja
	aFraction = multi(bFraction, (Frac)(n + 2));
	aFraction.print();

}
