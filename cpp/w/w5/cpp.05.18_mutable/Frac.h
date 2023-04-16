#pragma once

#include <iostream>
#include <string>

namespace OOP 
{
	class Frac
	{
	public:
		explicit Frac(int l = 0, int m = 0, const std::string& Opis = "") : _l(l), _m(m), _Opis(Opis)
		{}

		void SetOpis(const std::string& Opis) const
		{ _Opis = Opis; }

		//Tak byæ nie mo¿e
		//void SetLM(int l, int m) const
		void SetLM(int l, int m)
		{ _l = l; _m = m; }

		void printOut() const
		{ std::cout << _Opis << "= " << _l << "/" << _m << std::endl; }

	private:
		int _l;
		int _m;
		mutable std::string _Opis;
	};
}//End of namespace OOP