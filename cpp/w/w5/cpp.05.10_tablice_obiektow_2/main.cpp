#include <iostream>
#include <string>

//using namespace std;

class Miasto
{
public:
	friend std::ostream& operator<< (std::ostream& strm, const Miasto &K);
	
	Miasto() : m_szer(0), m_dl(0), m_wys(0), m_nazwa("")
	{}
	Miasto(double szer, double dl, double wys, std::string nazwa) : m_szer(szer), m_dl(dl), m_wys(wys), m_nazwa(nazwa)
	{}

private:
	double m_szer;
	double m_dl;
	double m_wys;
	std::string m_nazwa;
};
/////////////////////////////////////////////////////////////////////////
inline std::ostream& operator<< (std::ostream& strm, const Miasto &K)
{
	return strm << "Nazwa: " << K.m_nazwa << "\nDlugosc: " << K.m_dl << "\tSzeroksc: " << K.m_szer << "\tWysokosc: " << K.m_wys << std::endl;
}
/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;

	{
	Miasto aMiasto(40, 30, 150, "Krakow") ;

	Miasto bMiasto[4] = {
		Miasto(40, 30, 150, "Krakow"),
		Miasto(45, 30, 50, "Warszawa"),
		Miasto(50, 30, 0, "Sopot")
		};

	cout << aMiasto << bMiasto[0] << bMiasto[1] << bMiasto[2] << bMiasto[3];
	}
	{
	Miasto bMiasto[5] = {
		{ 40, 30, 150, "Krakow"}, 
		{ 45, 30, 50, "Warszawa"},
		{ 50, 30, 0, "Sopot"},
		};

	cout << bMiasto[0] << bMiasto[1] << bMiasto[2] << bMiasto[3];
	}
	
	// {
	// 	Miasto bMiasto[5] = {
	// 		40, 30, 150, "Krakow",
	// 		45, 30, 50, "Warszawa",
	// 		50, 30, 0, "Sopot"
	// 		};

	// 	cout << bMiasto[0] << bMiasto[1] << bMiasto[2] << bMiasto[3];
	// }
}
