#ifndef _Auto_H_
#define _Auto_H_

#include <iostream>

namespace OOP {
class Auto
{
public:
  Auto(int d = 0) : m_km(d) 
	{ std::cout << "Konstruktor Auto\n"; }

  virtual ~Auto() 
	{ std::cout << "Destruktor Auto\n"; }

  virtual void travel(int d) {
      m_km += d;
  }

	virtual void printTraveled() 
	{
      std::cout << "Auto przejechalo "
                << m_km << " km " << std::endl;
  }

protected:
  int m_km;
};

}  // namespace OOP

#endif    // _Auto_H_
