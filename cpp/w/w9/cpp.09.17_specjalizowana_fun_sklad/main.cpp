#include <iostream>
#include <string>
#include <exception>
#include "Fraction.h"
#include "OOPFunTemplates.h"

namespace OOP{
/////////////////////////////////////////////////////////////////////////
	template<typename T> class BoxOpis
	{
	public:

		void SetT(const T& obj)
		{	box = obj; }

		void SetOpis(const std::string opis)
		{ this->opis = opis;}

		T GetT () const
		{	return box;	}

		std::string GetOpis() const
		{ return opis; }

	private:
		T box;
		std::string opis;
	};
	/////////////////////////////////////////////////////////////////////////

	template<>
	void BoxOpis<Fraction>::SetT(const Fraction& K)
	{
		std::cout << "Specjalizowana funkcja skladowa dla Fraction\n";
		box = K;
	}

	template<typename T>
		std::ostream& operator<<(std::ostream& o, const BoxOpis<T> &K)
	{
		o << K.GetOpis().c_str() << ": "<< K.GetT();
		return o;
	}


}//End of namespace

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	using namespace std;

	OOP::BoxOpis<OOP::Fraction> aFrac;

	aFrac.SetT(OOP::Fraction(1/4));
	aFrac.SetOpis("Ulamek");

	cout << aFrac << endl << endl;

	OOP::BoxOpis<double> a;
	a.SetT(3.14159);
	a.SetOpis("M_PI");

	cout << a << endl;

	return 0;
}

