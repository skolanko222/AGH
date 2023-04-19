#include <iostream>
#include <string>
using namespace std;

class PointCollection;

class Point 
{ 
	friend class PointCollection;

	Point() : _x(0.0),  _y(0.0), _Opis("")
	{ cout << "Konstruktor domniemany Point(" << _Opis << ").\n"; }

	Point(double x, double y, const string& Opis = "") : _x(x), _y(y), _Opis(Opis)
	{cout << "Konstruktor Point(" << _Opis << ").\n"; }

	~Point()
	{ cout << "Destruktor Point(" << _Opis << ").\n"; }

	double _x; 
	double _y; 
	string _Opis;
}; 

/////////////////////////////////////////////////////////////////////////
class PointCollection 
{ 
public: 
	PointCollection()
	{ cout << "Konstruktor domniemany PointCollection.\n"; } 

	PointCollection(double x1, double y1, double x2, double y2, const string& opis1 = "", const string& opis2 = "") 
		: aPoint(x1, y1, opis1), bPoint(x2, y2, opis2)
	{ cout << "Konstruktor PointCollection.\n"; } 

	~PointCollection()
	{ cout << "Destruktor PointCollection.\n"; }
	void print();

private: 
	Point aPoint, bPoint; 
}; 
/////////////////////////////////////////////////////////////////////////
void PointCollection::print() 
{ 
	
	if(aPoint._Opis.length() > 0)
		cout << aPoint._Opis << "(x, y) = " << aPoint._x << ", " <<  aPoint._y << endl;
	else
		cout << "<bez_nazwy> " << "(x, y) = " << aPoint._x << ", " <<  aPoint._y << endl;

	if(bPoint._Opis.length() > 0)
		cout << bPoint._Opis << "(x, y) = " << bPoint._x << ", " <<  bPoint._y << endl << endl;
	else
		cout << "<bez_nazwy> " << "(x, y) = " << bPoint._x << ", " <<  bPoint._y << endl << endl;
} 
/////////////////////////////////////////////////////////////////////////
int main()
{
	//Niemo¿liwe jest utoworzenie obiektu Point
	//Point a;

	PointCollection *aPointCollection;
	aPointCollection = new PointCollection(1.1, 1.1, 2.2, 2.2, "pierwszy", "drugi");

	aPointCollection->print();
	delete aPointCollection;

	PointCollection cPointCollection;
	cPointCollection.print();

}
