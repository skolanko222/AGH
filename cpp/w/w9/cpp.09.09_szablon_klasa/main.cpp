#include <iostream>
#include "Fraction.h"
#include "OOPFunTemplates.h"

namespace OOP{

	template<typename T> 
	class Box
	{
	public:
		T box;
	};
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	using namespace std;

	OOP::Box<int> a, b;
	a.box = 1;
	b.box = 2;

	cout << "a.box = " << a.box << ", b.box = " << b.box << endl;
	OOP::swap(a, b);
	cout << "a.box = " << a.box << ", b.box = " << b.box << endl;
	

	OOP::Box<OOP::Fraction> aBoxFrac, bBoxFrac;

	aBoxFrac.box.SetL(1);
	aBoxFrac.box.SetM(2);

	bBoxFrac.box.SetL(1);
	bBoxFrac.box.SetM(5);

	cout << "aBoxFrac.box = " << aBoxFrac.box << ", bBoxFrac.box = " << bBoxFrac.box << endl;
	OOP::swap(aBoxFrac, bBoxFrac);
	cout << "aBoxFrac.box = " << aBoxFrac.box << ", bBoxFrac.box = " << bBoxFrac.box << endl;
}
