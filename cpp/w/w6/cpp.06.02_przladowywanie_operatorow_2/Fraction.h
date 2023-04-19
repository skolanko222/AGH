#ifndef _Fraction_H_
#define _Fraction_H_

#include <iostream>

class Fraction
{
public:
   friend std::ostream& operator<< (std::ostream& o, const Fraction& K);
   friend std::istream& operator>> (std::istream& i, Fraction& K);

	Fraction(int l = 0, int m = 1) : _l(l), _m(m)
		{}
	int getL() const
	{ return _l; }

	int getM() const
	{ return _m; }

	void setL(int l)
	{ _l = l;}
	
	void setM(int m)
	{ _m = m;}

	//funkcja konwertuj¹ca do float
	float toFloat() const
	{ return (float)_l/(float)_m; }

private:
	int _l;
	int _m;
};

/////////////////////////////////////////////////////////////////////////
inline std::ostream& operator<< (std::ostream& o, const Fraction& K)
{
	return o << K._l << "/" << K._m;
}

/////////////////////////////////////////////////////////////////////////
inline std::istream& operator>> (std::istream& i, Fraction& K)
{
	char tmp;
	return i >> K._l >> tmp >> K._m;
}

#endif