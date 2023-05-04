#include <iostream>
#include <string>
#include "Rec.h"

namespace OOP {

class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, const std::string& opis = "") : Rec(x, y), _opis(opis)
	{ std::cout << "Konstruktor RecLbl(" << (_opis.length() > 0 ? _opis : "NoName") << ")\n"; }

	void Setopis(const std::string& opis)
	{ _opis = opis; }

	std::string Getopis() const
	{ return _opis; }

protected:
	std::string _opis;
};
}//end of namespace OOP

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;

	const RecLbl aRecLbl;

	//zdefiniowany przez nas konstruktor kopiuj�cy Rec musi by� wywo�any z const
	RecLbl bRecLbl {aRecLbl};
}

