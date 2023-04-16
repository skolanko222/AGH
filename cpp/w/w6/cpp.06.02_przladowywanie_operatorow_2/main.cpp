#include <iostream>
#include <string>
#include "Fraction.h"

/////////////////////////////////////////////////////////////////////////
Fraction operator*(const Fraction &K1, const Fraction &K2)
{
	return Fraction(K1.getL() * K2.getL(), K1.getM() * K2.getM());
}

/////////////////////////////////////////////////////////////////////////
Fraction operator-(const Fraction &K)
{
	return Fraction(-K.getL(), K.getM());
}

/////////////////////////////////////////////////////////////////////////
Fraction operator-(const Fraction &K1, const Fraction &K2)
{
	return Fraction(K1.getL()*K2.getM() - K1.getM()*K2.getL(),
	              K1.getM()*K2.getM());
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;
	
	Fraction aFraction;
	Fraction bFraction;

	cout << "Podaj aFraction: ";
	cin >> aFraction;

	cout << "Podaj bFraction: ";
	cin >> bFraction;

	cout << "aFraction * bFraction = " << aFraction * bFraction << endl;
	cout << "-bFraction = " << -bFraction << endl;

	cout << "aFraction - bFraction = " << aFraction - bFraction << endl;
	cout << "1 - bFraction = " << 1 - bFraction << endl;
	cout << "bFraction - 1 = " << bFraction - 1 << endl;

	cout << "2 * bFraction = " << 2 * bFraction << endl;
	cout << "bFraction * 2 = " << bFraction * 2 << endl;
}
