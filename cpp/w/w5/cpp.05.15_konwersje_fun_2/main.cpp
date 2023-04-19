#include <iostream>
#include <string>

class Number
{
public:
	Number(int n = 0) : _n(n)
	{}
	int Get() const
	{ return _n; }

	void print() const
	{ std::cout << _n << std::endl; }

private:
	int _n;
};

/////////////////////////////////////////////////////////////////////////
class Frac
{
public:
	friend Frac multi(const Frac& a, const Frac& b);
	
	Frac(int l = 0, int m = 1) : _l(l), _m(m)
	{}

	Frac(int l) : _l(l), _m(1)
	{std::cout << "\nDziala konstruktor konwertujacy (int)." << std::endl; }
	
	Frac(const Number& n) : _l(n.Get()), _m(1)
	{ std::cout << "\nDziala konstruktor konwertujacy (Number)." << std::endl; }

	//funkcja konwertuj¹ca do double
	operator double() const
	{ 
		std::cout << "\nDziala funkcja konwertujaca do double." << std::endl;
		return (double)_l/(double)_m; 
	}
	
	//funkcja konwertuj¹ca do Number
	operator Number() const
	{ 
		std::cout << "\nDziala funkcja konwertujaca do Number." << std::endl;
		return Number((int)((double)_l/(double)_m + 0.5)); 
	}

	void print() const
	{ std::cout << _l << "/" << _m << std::endl; }

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
int sum(const Number& a, const Number& b)
{
	return a.Get() + b.Get();
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;
	
	Frac aFraction(4, 3);
	Number aNumber(1);
	
	//wykorzystujemy funkcje konwertuj¹c¹ przy wywo³aniu funkcji której argumentami s¹ dwa obiekty typu Number
	cout << sum(aNumber, aFraction) << endl;
	cout << multi(aFraction, aNumber) << endl;	
}