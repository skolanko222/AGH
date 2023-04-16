#include <iostream>
#include <string>
#include "Rec.h"

/////////////////////////////////////////////////////////////////////////
class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, std::string Opis = "") : _Opis(Opis) {
		_x = x;
		_y = y;
	}
	void SetOpis(std::string Opis)
	{_Opis = Opis;}

	std::string GetOpis() const
	{ return _Opis;}

protected:
	std::string _Opis;
};

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[]) {
	using namespace std;
	
	const RecLbl bRecLbl(5, 5, "bRecLbl");
	
	cout << "Pole " << bRecLbl.GetOpis() << " = " << bRecLbl.Pole() << endl;
}

