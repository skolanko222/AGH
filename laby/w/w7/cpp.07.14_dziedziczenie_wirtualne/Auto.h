#ifndef _CAUTO_H_
#define _CAUTO_H_

#include <iostream>
#include "Trans.h"

namespace OOP {
class Auto : virtual public Trans
{
public:
  Auto(int d = 0) : Trans(d) 
	{  }

	~Auto()
  {  }

  void travel(int d) 
	{
      m_km += d;
  }

	void printTraveled() 
	{
      std::cout << "Auto przejechalo "
                << m_km << " km " << std::endl;
  }
};

}  // namespace OOP

#endif    // _CAUTO_H_
