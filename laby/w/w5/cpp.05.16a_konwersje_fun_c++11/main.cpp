#include <iostream>
#include <string>

class Number
{
public:
	explicit Number(int n = 0) : m_n(n)
	{}
	int Get() const
	{ return m_n; }

	void print() const
	{ std::cout << m_n << std::endl; }

private:
	int m_n;
};

/////////////////////////////////////////////////////////////////////////
class Frac
{
public:
	friend Frac multi(const Frac& a, const Frac& b);
	
	Frac(int l = 0, int m = 1) : m_l(l), m_m(m)
	{}

	Frac(int l) : m_l(l), m_m(1)
	{std::cout << "Dziala konstruktor konwertujacy (int)." << std::endl; }
	
	explicit Frac(Number n) : m_l(n.Get()), m_m(1)
	{ std::cout << "Dziala konstruktor konwertujacy Frac(Number)." << std::endl; }

	//funkcja konwertuj¹ca do double
	explicit operator double() const
	{ 
		std::cout << "Dziala funkcja konwertujaca do double." << std::endl;
		return (double)m_l/(double)m_m; 
	}
	
	//funkcja konwertuj¹ca do Number
	explicit operator Number() const
	{ 
		std::cout << "Dziala funkcja konwertujaca do Number." << std::endl;
		return Number((int)((double)m_l/(double)m_m + 0.5)); 
	}

	void print() const
	{ std::cout << m_l << "/" << m_m << std::endl; }

private:
	int m_l;
	int m_m;
};

/////////////////////////////////////////////////////////////////////////
Frac multi(const Frac& a, const Frac& b)
{
	Frac tmp;
	tmp.m_l = a.m_l * b.m_l;
	tmp.m_m = a.m_m * b.m_m;
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
	cout << "  --- Suma: " 
		<< sum(aNumber, static_cast<Number>(aFraction)) << endl;
	cout << "  --- Multi: " 
		<< static_cast<double>(multi(aFraction, static_cast<Frac>(aNumber))) << endl;	
}