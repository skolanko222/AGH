#include <iostream>
#include <string>

namespace OOP {
	class Frac
	{
	public:
		friend Frac multi1(Frac *a, Frac *b);
		friend Frac multi2(Frac &a, Frac &b);

		Frac(int l = 0, int m = 1) : m_l(l), m_m(m)
			{}
		
		//funkcja konwertuj¹ca do float
		operator float() const
		{ 
			std::cout << "\nDziala funkcja konwertujaca do float." << std::endl;
			return (float)m_l/(float)m_m; 
		}
		
		void print() const
		{ std::cout << m_l << "/" << m_m << std::endl; }

	private:
		int m_l;
		int m_m;
	};
}//End of namespace OOP