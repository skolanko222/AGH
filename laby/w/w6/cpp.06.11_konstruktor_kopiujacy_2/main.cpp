#include <iostream>
#include <string>
#include "Rec.h"

class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, const std::string& Opis = "") : Rec(x, y), m_Opis(Opis)
	{ }


	RecLbl(const RecLbl& v): Rec(v) { 
	// RecLbl(const RecLbl& v) { 
		m_Opis = v.m_Opis;
		std::cout << __PRETTY_FUNCTION__ << std::endl; 
	}


	void SetOpis(std::string Opis)
	{ m_Opis = Opis; }

	std::string GetOpis() const
	{ return m_Opis; }

protected:
	std::string m_Opis;
};

int main(int argc, char * argv[])
{
	using namespace std;


	const RecLbl aRecLbl(1, 2);

	RecLbl bRecLbl = aRecLbl;

	RecLbl cRecLbl;
	cRecLbl = bRecLbl;

	cRecLbl.rys();
}

