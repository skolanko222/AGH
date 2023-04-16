#include <iostream>

/////////////////////////////////////////////////////////
class Point {
public :

	friend Point& operator--(Point& K);
	friend Point operator--(Point& K, int);

	Point(double a = 0, double b = 0) : _a(a), _b(b) {}
	
	Point& operator++()	{
		++_a; ++_b;
		return *this;
	}

	Point operator++(int){
		Point tmp = *this;  
		++_a; ++_b; 
		return tmp; 
	}

	double GetA() const
	{return _a;}
	
	double GetB() const
	{return _b;}

	void SetA(double a)
	{_a = a;}
	
	void SetB(double b)
	{_b = b;}

private:
  double _a;
  double _b;
};
/////////////////////////////////////////////////////////

Point& operator--(Point& K)
{	--K._a; --K._b;	return K;	}
/////////////////////////////////////////////////////////

Point operator--(Point& K, int)
{	Point tmp = K;  --K._a; --K._b; return tmp; }

std::ostream& operator<<(std::ostream& strm, const Point &K);
std::istream& operator>>(std::istream& strm, Point &K);

/////////////////////////////////////////////////////////
int main()
{
	using namespace std;

	Point aPoint;
	
	cout << aPoint << endl;
	
	cout << aPoint++ << endl;
	cout << aPoint << endl;
	
	cout << ++aPoint << endl;
	cout << aPoint << endl;

	cout << aPoint-- << endl;
	cout << aPoint << endl;

	cout << --aPoint << endl;
	cout << aPoint << endl;
}


/////////////////////////////////////////////////////////
inline std::ostream& operator<<(std::ostream& strm, const Point &K)
{
	return (strm << K.GetA() << "," << K.GetB());	
}

/////////////////////////////////////////////////////////
inline std::istream& operator>>(std::istream& strm, Point &K)
{
	double a, b;
	char tmp;
	strm >> a >> tmp >> b;
	K.SetA(a);
	K.SetB(b);	
	return strm; 
}
