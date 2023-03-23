#ifndef _Amf_H_
#define _Amf_H_

#include "Auto.h"
#include "Lodz.h"

namespace OOP 
{
class Amf : public Auto, public Lodz 
{
public:
  Amf(int k = 0, int s = 0) : Auto(k), Lodz(s) 
	{ std::cout << "Konstruktor Amf\n"; }

  virtual ~Amf() 
	{ std::cout << "Destruktor Amf\n"; }

	virtual void printTraveled() 
	{
      std::cout << "Amfibia pokonala "
                << m_km << " km i " << m_sm << " mil " << std::endl;
  }
};

}  // namespace OOP
#endif    // _Amf_H_
