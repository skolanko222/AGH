#include "Punkt.h"

template<> void swap<Punkt>(Punkt &a, Punkt &b) 
{
	int x = a.wsp<'x'>();
	int y = a.wsp<'y'>();
	a.setWSP<'x'>(b.wsp<'x'>());
	a.setWSP<'y'>(b.wsp<'y'>());
	b.setWSP<'x'>(x);
	b.setWSP<'y'>(y);
}

std::ostream & operator<<(std::ostream &a, const Punkt &obj)
{
	return a << obj._str << "(" << obj._x << ", " << obj._y << ")";
}