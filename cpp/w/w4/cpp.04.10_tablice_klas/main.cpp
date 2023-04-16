#include <iostream>

class Point 
{ 
public: 
	Point(double x = 0.0, double y = 0.0)
	{_x = x;  _y = y; }
	
	void SetX(double x)
		{_x = x;}

	void SetY(double y)
		{_y = y;}

	double GetX() const
		{ return _x; }

	double GetY() const
		{ return _y; }

	void printOut() const
		{std::cout << _x << ", " << _y;}

private: 
	double _x; 
	double _y; 
}; 
/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;

	const unsigned int n = 6;
	Point Tab1[n];

	//referencja do pierwszego elementu tablicy Tab1
	Point &Ref = Tab1[0];
	
	//wype³nienie Tab1
	for(unsigned int i = 0; i < n; ++i)
		Tab1[i].SetX(i), Tab1[i].SetY(i+1);

	cout << "------------- Tab1 -------------------\n";
	//wypisanie Tab1
	for(unsigned int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		Tab1[i].printOut();
		cout << endl;
	}
	
	cout << "----------- Ref - Tab[0] -------------\n";

	//zmiania Tab1[0] przez referencje
	Ref.SetX(1.1);
	Ref.SetY(1.1);

	//wypisanie Tab1[0]
	Tab1[0].printOut();
	cout << "\n------------ Tab2 --------------------\n";

	//utworzenie Tab2 z jednoczesn¹ inicjalizacj¹ 
	Point Tab2[n] = {Point(1, 1),
										Point(2, 2),
										Point(3, 3)};

	//wypisanie Tab2
	for(unsigned int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		Tab2[i].printOut();
		cout << endl;
	}

	cout << "-------------- Tab3 ------------------\n";
	//utworzenie Tab3 z jednoczesn¹ inicjalizacj¹ 
	//u¿ywaj¹c niejawnych wywo³añ konstruktorów
	Point Tab3[n] = {1, 1,
										2, 2,
										3, 3};

	//wypisanie Tab3
	for(unsigned int i = 0; i < n; ++i)
	{
		cout << i << ": ";
		Tab3[i].printOut();
		cout << endl;
	}
}
