#ifndef _OOP_FUN_TEMPLATES_H_
#define _OOP_FUN_TEMPLATES_H_

#include <iostream>

namespace OOP 
{
	// template<typename T> void swap(T& a, T& b)
	template<class T> void swap(T& a, T& b)
	{
		T tmp = T(a);
		a = b;
		b = tmp;
	}

/////////////////////////////////////////////////////////////////////////
	template<typename T1, typename T2> T1 max(const T1& a, const T2& b)
	{
		return (a < b) ? b : a;
	}

/////////////////////////////////////////////////////////////////////////
	template<typename T1, typename T2> T1 min(const T1& a, const T2& b)
	{
		return (a < b) ? a : b;
	}

}//End of namespace OOP

#endif //_OOP_FUN_TEMPLATES_H_