#include <iostream>
#include <string>
#include "Rec.h"

namespace OOP {

class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, const std::string& Opis = "") : _Opis(Opis)
	{
		_x = x;
		_y = y;
		std::cout << "Konstruktor RecLbl(" << _Opis << ")\n"; 
	}

	~RecLbl()
	{std::cout << "Destruktor RecLbl(" << _Opis << ")\n"; }

	void SetOpis(const std::string& Opis)
	{_Opis = Opis;}

	const std::string& GetOpis() const
	{ return _Opis;}

protected:
	std::string _Opis;
};

}//end of namespace OOP

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;

	const RecLbl aRecLbl(5, 5, "aRecLbl");
	cout << "--------------------------------------" << endl;
	RecLbl bRecLbl(5, 5, "bRecLbl");
	cout << "--------------------------------------" << endl;
}

