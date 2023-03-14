#include <string>
#include "Point.h"

std::ostream &operator<<(std::ostream &o, Point obj)
{
	return o << obj.Name() << '[' << obj.getX() << ',' << obj.getY() << ']';
}
