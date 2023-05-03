#include <iostream>
#include "Wektor2D.h"
void print(const Wektor2D * temp)
{
	std::cout << temp->_str << " (" << temp->_x << ", " << temp->_y << ")\n";
}

void print2(const Wektor2D & temp)
{
	std::cout << temp._str << " (" << temp._x << ", " << temp._y << ")\n";
}