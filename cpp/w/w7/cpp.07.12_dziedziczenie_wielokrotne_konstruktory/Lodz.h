#ifndef _Lodz_H_
#define _Lodz_H_

#include <iostream>

namespace OOP {

class Lodz 
{
public:
  Lodz(int d = 0) : m_sm(d) 
	{ std::cout << "Konstruktor Lodz\n"; }
	
  virtual ~Lodz()
	{ std::cout << "Destruktor Lodz\n"; }
	
  virtual void travel(int d) 
	{
      m_sm += d;
  }
  
	virtual void printTraveled() 
	{
      std::cout << "Lodz przeplynela "
                << m_sm << " mil " << std::endl;
  }

protected:
  int m_sm;
};

}  // namespace OOP

#endif    // _Lodz_H_
