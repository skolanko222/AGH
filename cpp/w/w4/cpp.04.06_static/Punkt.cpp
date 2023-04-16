#include <iostream>
#include "Punkt.h"

using std::cout;
using std::endl;

Punkt::Punkt()
{
	n++;

	_x = 0;
	_y = 0;

	cout << "Dziala konstruktor\n";
}
/////////////////////////////////////////////////////////////////////////
Punkt::Punkt(float x, float y)
{
	n++;

	_x = x;
	_y = y;
	cout << "Dziala konstruktor z inicjalizacja "
		   << "_x, _y = " << _x << ", " << _y << endl;
}
/////////////////////////////////////////////////////////////////////////
Punkt::~Punkt()
{
	n--;
	cout << "Dziala destruktor\n";
}
/////////////////////////////////////////////////////////////////////////
float Punkt::GetX() const
{
	return _x;
}
/////////////////////////////////////////////////////////////////////////
float Punkt::GetY() const
{
	return _y;
}
/////////////////////////////////////////////////////////////////////////

int Punkt::n = -10; //nie ma slowa static
