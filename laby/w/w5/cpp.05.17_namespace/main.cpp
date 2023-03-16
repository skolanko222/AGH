#include <iostream>
#include <string>
#include "Frac.h"

namespace OOP {
	Frac multi1(Frac *a, Frac *b);
	Frac multi2(Frac &a, Frac &b);

namespace foo {
    namespace bar {
         namespace baz {
         	struct A{};
         }
     }
 }

}//End of namespace OOP

/////////////////////////////////////////////////////////////////////////
int main()
{
	const OOP::Frac aFraction(1, 2);



	
	using OOP::Frac;
	Frac bFraction(1, 2);
	Frac cFraction;
	
	cFraction = OOP::multi1(const_cast<Frac*>(&aFraction), &bFraction);
	cFraction.print();

	using namespace OOP;
	
	const Frac &dFraction = bFraction;

	//cFraction = multi2(dFraction, bFraction); //BLAD kompilacji
	cFraction = multi2(const_cast<Frac&>(dFraction), bFraction);
	cFraction.print();
	
	namespace fbz = foo::bar::baz;
	fbz::A a;
	a = a;
}

/////////////////////////////////////////////////////////////////////////
namespace OOP {
	Frac multi1(Frac *a, Frac *b)
	{
		Frac tmp;
		tmp.m_l = a->m_l * b->m_l;
		tmp.m_m = a->m_m * b->m_m;
		return tmp;
	}

	/////////////////////////////////////////////////////////////////////////
	Frac multi2(Frac &a, Frac &b)
	{
		Frac tmp;
		tmp.m_l = a.m_l * b.m_l;
		tmp.m_m = a.m_m * b.m_m;
		return tmp;
	}
}//End of namespace OOP
