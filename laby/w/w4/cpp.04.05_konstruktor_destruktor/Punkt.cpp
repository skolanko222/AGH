#include "Punkt.h"
#include <iostream>

using std::cout;
using std::endl;

Punkt::Punkt()
{
	_x = 0;
	_y = 0;
	cout << "Dziala konstruktor\n";
}
/////////////////////////////////////////////////////////////////////////
Punkt::Punkt(double x, double y)
{
	_x = x;
	_y = y;
	cout << "Dziala konstruktor z inicjalizacja "
		   << "m_x, m_y = " << _x << ", " << _y << endl;
}
/////////////////////////////////////////////////////////////////////////
Punkt::~Punkt()
{
	cout << "Dziala destruktor "
		   << "m_x, m_y = " << _x << ", " << _y << endl;
}
/////////////////
double Punkt::GetX() const
{
	return _x;
}
/////////////////////////////////////////////////////////////////////////
double Punkt::GetY() const
{
	return _y;
}
/////////////////////////////////////////////////////////////////////////
