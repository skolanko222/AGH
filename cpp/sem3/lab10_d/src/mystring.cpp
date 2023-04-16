#include <iostream>
#include "mystring.h"


namespace mystring 
{
std::ostream &operator<<(std::ostream &o,const String &n)
	{
		return o << n._napis << std::endl;
	}
	
}