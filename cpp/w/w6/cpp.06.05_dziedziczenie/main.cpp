#include <iostream>

class Shape
{
public:
	double GetX() const;
	double GetY() const;
	void SetX(double x);
	void SetY(double y);
	double Pole() { return 0.0; }

	double x,y;
};

inline double Shape::GetX() const {	return x; }
inline double Shape::GetY() const {	return y; }
inline void Shape::SetX(double x) { this->x = x; }
inline void Shape::SetY(double y) {	this->y = y; }

/////////////////////////////////////////////////////////////////////////
class Rec : public Shape
{
public:
	double Pole();
	void rys();

	double a = 10, b = 5;
};

/////////////////////////////////////////////////////////////////////////
inline double Rec::Pole()
{
	return a*b;
}

/////////////////////////////////////////////////////////////////////////
inline void Rec::rys()
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
	cout << "Pole Rec, ale wywolana funkcja z Shape = " << bRec.Shape::Pole() << endl;
}
