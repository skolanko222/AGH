#include <iostream>
#include <string>
#include "Rec.h"

/////////////////////////////////////////////////////////////////////////
namespace OOP {

class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, const std::string& Opis = "") : Rec(x, y), _Opis(Opis)
	{ std::cout << "Konstruktor RecLbl(" << (_Opis.length() > 0 ? _Opis : "NoName") << ")\n"; }

	void SetOpis(std::string Opis)
	{ _Opis = Opis; }

	std::string GetOpis() const
	{ return _Opis; }

protected:
	std::string _Opis;
};
}//end of namespace OOP

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[]) {
	using namespace std;
	using namespace OOP;

	const RecLbl aRecLbl;
}

