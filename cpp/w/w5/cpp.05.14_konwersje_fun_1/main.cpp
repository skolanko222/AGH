#include <iostream>
#include <string>

class Frac
{
public:
	friend Frac multi(const Frac& a, const Frac& b);
	
	Frac(int l = 0, int m = 1) : _l(l), _m(m)	{}

	//konstruktor s³u¿¹cy jako konwerter z liczby typu int
	Frac(int l) : _l(l), _m(1) {
		std::cout << "\nDziala konstruktor konwertujacy (int)." << std::endl; 
	}
	
	//funkcja konwertuj¹ca do double
	operator double() const { 
		std::cout << "\nDziala funkcja konwertujaca do double." << std::endl;
		return (double)_l/(double)_m; 
	}

	void print() const { 
		std::cout << _l << "/" << _m << std::endl; 
	}

private:
	int _l;
	int _m;
};
/////////////////////////////////////////////////////////////////////////
Frac multi(const Frac& a, const Frac& b)
{
	Frac tmp;
	tmp._l = a._l * b._l;
	tmp._m = a._m * b._m;
	return tmp;
}
/////////////////////////////////////////////////////////////////////////
double sum(double a, double b)
{
	return a + b;
}
/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;
	
	Frac aFraction(1, 2);
	
	//wykorzystujemy funkcje konwertuj¹c¹ przy wywo³aniu funkcji której argumentami s¹ dwie liczby typu double
	cout << sum(1.0, aFraction) << endl;

	cout << 1 - aFraction << endl;
}
