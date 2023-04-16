#include <iostream>
#include <string>

using namespace std;

class Point2 
{ 
public: 
	Point2() : m_x(0.0),  m_y(0.0), m_Opis("")
	{ cout << "Konstruktor domniemany Point2(" << m_Opis << ").\n"; }

	Point2(double x, double y, const string& Opis) : m_x(x),  m_y(y), m_Opis(Opis)
	{ cout << "Konstruktor Point2(" << m_Opis << ").\n"; }

	Point2(const Point2 &K)
	// Point2(Point2 &K) 
		: m_x(K.m_x),  m_y(K.m_y), m_Opis(K.m_Opis)
	{
		m_Opis = ("InnyNizObiektuKopiwanego");
		cout << "Konstruktor kopiujacy Point2(" << m_Opis << ").\n";
	}

	~Point2()
	{ cout << "Destruktor Point2(" << m_Opis << ").\n"; }
	
	void print() const; 
	void SetOpis(const string& Opis)
	{m_Opis = Opis; }

private: 
	double m_x; 
	double m_y; 
	string m_Opis;
}; 
/////////////////////////////////////////////////////////////////////////

void Point2::print() const
{ 
	if(m_Opis.length() > 0)
		cout << m_Opis << "(x, y) = " << m_x << ", " <<  m_y << endl;
	else
		cout << "<bez_nazwy> " << "(x, y) = " << m_x << ", " <<  m_y << endl;
} 
/////////////////////////////////////////////////////////////////////////
inline void fun(Point2 K)
{}
/////////////////////////////////////////////////////////////////////////
inline Point2 fun()
{	Point2 K;	return K; }

int main()
{
	cout << "-------------- 1 -----------------\n";
	const Point2 aPoint2(1, 1, "pierwszy");
	const Point2 bPoint2 {aPoint2};
	
	cout << "\n-------------- 2 -----------------\n";
	aPoint2.print();
	bPoint2.print();

	cout << "\n-------------- 3 -----------------\n";
	fun(bPoint2);
	cout << "\n-------------- 4 -----------------\n";
	// fun();
	// cout << "\n-------------- 5 -----------------\n";
}
