#include <iostream>
#include <string>

using namespace std;

class Point 
{ 
public: 
	Point() : m_x(0.0),  m_y(0.0), m_Opis("")
	{ cout << "Konstruktor domniemany Point(" << m_Opis << ").\n"; }

	Point(double x, double y, const string& Opis = "") : m_x(x), m_y(y), m_Opis(Opis)
	{cout << "Konstruktor Point(" << m_Opis << ").\n"; }

	Point(Point& K)
	{ 
		m_Opis = K.m_Opis;
		m_x = K.m_x;
		m_y = K.m_y;
		cout << "Konstruktor kopiujący Point(" << K.m_Opis << ").\n"; 
	}

	~Point()
	{ cout << "Destruktor Point(" << m_Opis << ").\n"; }
	
	void print();
	void SetOpis(string Opis)
	{m_Opis = Opis; }

private: 
	double m_x; 
	double m_y; 
	string m_Opis;
}; 
/////////////////////////////////////////////////////////////////////////
void Point::print() 
{ 
	if(m_Opis.length() > 0)
		cout << m_Opis << "(x, y) = " << m_x << ", " <<  m_y << endl;
	else
		cout << "<bez_nazwy> " << "(x, y) = " << m_x << ", " <<  m_y << endl;
} 
/////////////////////////////////////////////////////////////////////////
int main()
{
	cout << "----------- Start ----------------\n";

	Point aPoint(1, 1, "pierwszy");
	Point bPoint = aPoint;	//dzia³a konstruktor kopiuj¹cy, a nie operator =
	// Point bPoint(aPoint);
	
	Point cPoint;
	cPoint = bPoint;

	aPoint.print();
	bPoint.print();
	cPoint.print();

	bPoint.SetOpis("drugi");
	cPoint.SetOpis("trzeci");

}
