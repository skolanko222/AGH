#ifndef _CLODZ_H_
#define _CLODZ_H_

#include <iostream>
#include "Trans.h"

namespace OOP {
class Lodz : virtual public Trans
{
public:
  Lodz(int d = 0) : Trans(d) 
	{  }

	~Lodz()
  { }
  	
  void travel(int d) 
	{
      m_km += d;
  }
  
	void printTraveled() 
	{
      std::cout << "Lodz przeplynela "
                << m_km << " km " << std::endl;
  }
};

}  // namespace OOP

#endif    // _CLODZ_H_
