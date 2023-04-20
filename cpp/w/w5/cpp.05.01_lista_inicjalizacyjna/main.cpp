#include <iostream>
#include <string>

class Point 
{ 
public: 

	Point(double x = 0, double y = 0, std::string Opis = "") : _x(x), _y(y), _Opis(Opis)
	, _cxx_11 {1010}
	{
		print();
	}

	void print() const;

private: 
	double _x = 0; 
	double _y = 0; 
	std::string _Opis;

	int _cxx_11 = 11; //wg std c++11

	static double _s;
	double _d = _s;
}; 
/////////////////////////////////////////////////////////////////////////
void Point::print() const
{ 
	if(_Opis.length() > 0)
		std::cout << _Opis << "(x, y) = " << _x << ", " <<  _y << ", " <<  _cxx_11 << std::endl;
	else
		std::cout << "<bez_nazwy> " << "(x, y) = " << _x << ", " <<  _y << ", " <<  _cxx_11 << std::endl;
} 
/////////////////////////////////////////////////////////////////////////

double Point::_s = 7;

int main()
{
	Point aPoint;
	Point bPoint {1, 1, "bPoint"};
	Point cPoint = Point(2, 2, "cPoint");
	Point dPoint(3, 3);
	

	// int* a = new int;

	aPoint.print();
	bPoint.print();
	cPoint.print();
	dPoint.print();
}
