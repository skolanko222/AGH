#include <iostream>

class CPoint 
{ 
public: 
	double x; 
	double y; 

	CPoint(double x = 0, double y = 0)
		{ this->x = x; this->y = y;		}

	void print()
		{std::cout << x << ", " << y << std::endl; }
}; 
/////////////////////////////////////////////////////////////////////////
struct Point
{
	double x;
	double y;

	Point(double x = 0, double y = 0)
		{ this->x = x; this->y = y;		}

	void print()
		{std::cout << x << ", " << y << std::endl; }
};

/////////////////////////////////////////////////////////////////////////
int main()
{
	CPoint x1(11, 11);
	Point x2(22, 22);

	x1.x = 1;
	x1.y = 1;
	x1.print();

	x2.x = 2;
	x2.y = 2;
	x2.print();
}

