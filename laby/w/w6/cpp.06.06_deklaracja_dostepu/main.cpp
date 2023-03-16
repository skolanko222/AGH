#include <iostream>

class Shape
{
public:
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);
	double Pole()
	{ return 0.0; }

	double x,y;
};
/////////////////////////////////////////////////////////////////////////
inline double Shape::GetX() const
{
	return x;
}

/////////////////////////////////////////////////////////////////////////
inline double Shape::GetY() const
{
	return y;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetX(double x)
{
	this->x = x;
}

/////////////////////////////////////////////////////////////////////////
inline void Shape::SetY(double y)
{
	this->y = y;
}

/////////////////////////////////////////////////////////////////////////
// class Rec : private Shape
class Rec: Shape
{
public:
	// Shape::SetX; //c++03
	using Shape::SetX; //c++11
	// Shape::SetY;
	using Shape::SetY;

	double Pole() const;
	void rys() const;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole() const
{
	return x*y;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys() const
{
	std::cout << "Rysuj Rec\n";
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	Shape aShape;
	Rec bRec;

	cout << "Pole Shape = " << aShape.Pole() << endl;

	bRec.SetX(5.0);
	bRec.SetY(4.0);
	cout << "Pole Rec = " << bRec.Pole() << endl;
	
	//niemo¿liwe bo brak dostepu ze wzgledu na prywatne dziedziczenie
	//cout << "CRec.X = " << bRec.GetX() << endl;
}
