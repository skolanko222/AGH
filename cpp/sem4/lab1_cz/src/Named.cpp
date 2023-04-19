#include <string>
#include "Named.h"

std::string operator>>(std::string n, Named &obj)
{
	obj.setName(n);
	return n;
}