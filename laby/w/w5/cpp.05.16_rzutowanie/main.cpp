#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////
class Frac
{
public:
	friend Frac multi1(Frac *a, Frac *b);
	friend Frac multi2(Frac &a, Frac &b);

	Frac(int l = 0, int m = 1) : m_l(l), m_m(m) {}

	//konstruktor s³u¿¹cy jako konwerter z liczby typu int
	Frac(int l) : m_l(l), m_m(1)
		{std::cout << "\nDziala konstruktor konwertujacy (int)." << std::endl; }
	
	//funkcja konwertuj¹ca do float
	operator float() const { 
		std::cout << "\nDziala funkcja konwertujaca do float." << std::endl;
	  return (float)m_l/(float)m_m; 
	}
	
	void print() const
	{ std::cout << m_l << "/" << m_m << std::endl; }

private:
	int m_l;
	int m_m;
};

/////////////////////////////////////////////////////////////////////////
Frac multi1(Frac *a, Frac *b)
{
	Frac tmp;
	tmp.m_l = a->m_l * b->m_l;
	tmp.m_m = a->m_m * b->m_m;
	return tmp;
}

/////////////////////////////////////////////////////////////////////////
Frac multi2(Frac &a, Frac &b)
{
	Frac tmp;
	tmp.m_l = a.m_l * b.m_l;
	tmp.m_m = a.m_m * b.m_m;
	return tmp;
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;

	double  x = 1.75;
	int n;

	n = static_cast<int>(x);
	cout << "x, n = " << x << ", " << n << endl;

	const Frac aFraction(1, 2);
	Frac bFraction(1, 2);
	Frac cFraction;
	const Frac &dFraction = bFraction;
	
	//wywo³anie funkcji multi która nie gwarantuje ¿e nie zmieni obiektów
	// cFraction = multi1(&aFraction, &bFraction); //BLAD kompilacji
	cFraction = multi1(const_cast<Frac*>(&aFraction), &bFraction);
	cFraction.print();
	
	// cFraction = multi2(dFraction, bFraction); //BLAD kompilacji
	cFraction = multi2(const_cast<Frac&>(dFraction), bFraction);
	cFraction.print();
}
