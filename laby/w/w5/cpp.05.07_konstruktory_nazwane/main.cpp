#include <iostream>
#include <cmath>
 
class Point 
{
public:
	static Point rectangular(double x, double y);      // Wsp. prostokatne
	static Point polar(double radius, double angle);   // Wsp. biegunowe

	double GetX() const
	{ return _x; }

	double GetY() const
	{ return _y; }

	double& GetX()
	{ return _x; }

	double& GetY()
	{ return _y; }

private: //zapobiegnie mo¿liwoœci dziedziczenia
	Point(double x=0, double y=0);
	double _x, _y;
};
 
inline Point::Point(double x, double y) : _x(x), _y(y) 
{}

inline Point Point::rectangular(double x, double y)
{ return Point(x, y); }

inline Point Point::polar(double radius, double angle)
{ return Point(radius*cos(angle), radius*sin(angle)); } 

/////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	using namespace std;

	const Point p1 = Point::rectangular(5.7, 1.2);   // Wsp. prostokatne
	Point p2 = Point::polar(5.7, 1.2);         // Wsp. biegunowe

	cout << "Point p1: " << p1.GetX() << ", " << p1.GetY() << endl;
	cout << "Point p2: " << p2.GetX() << ", " << p2.GetY() << endl;
	cout << "-- Point p2: " << (p2.GetX() = 1.2345) << ", " << p2.GetY() << endl;
}

