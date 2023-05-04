#include <iostream>
#include <typeinfo>
#include "Fraction.h"
#include "OOPFunTemplates.h"

namespace OOP{

	template<typename T, int rozmiar> 
	class Box
	{
	public:
		T box[rozmiar];
		Box() : m_size(rozmiar)
		{}
	
	private:
		int m_size;
	};
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	using namespace std;

	OOP::Box<int, 10> a;
	OOP::Box<int, 5+5> b;
	
	for(int i = 0; i < 10; ++i)
	{
		a.box[i] = 1;
		b.box[i] = 2;
	}

	cout << "a.box[1] = " << a.box[1] << ", b.box[1] = " << b.box[1] << endl;

	OOP::swap(a, b);
	cout << "a.box[1] = " << a.box[1] << ", b.box[1] = " << b.box[1] << endl;
	

	OOP::Box<OOP::Fraction, 1> aBoxFrac, bBoxFrac;
	OOP::Box<OOP::Fraction, 2> cBoxFrac;

	cout << typeid(aBoxFrac).name() << "\n" 
		<< typeid(bBoxFrac).name() << "\n" 
		<< typeid(cBoxFrac).name() << endl;
	
	aBoxFrac.box[0].SetL(1);
	aBoxFrac.box[0].SetM(2);

	bBoxFrac.box[0].SetL(1);
	bBoxFrac.box[0].SetM(5);

	cout << "aBoxFrac.box[0] = " << aBoxFrac.box[0] 
		<< ", bBoxFrac.box[0] = " << bBoxFrac.box[0] << endl;
	
	OOP::swap(aBoxFrac, bBoxFrac);

	cout << "aBoxFrac.box[0] = " << aBoxFrac.box[0] 
		<< ", bBoxFrac.box[0] = " << bBoxFrac.box[0] << endl;

	//Takie wywo�anie jest b��dem
	// OOP::swap(aBoxFrac, cBoxFrac);
}

