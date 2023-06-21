#include <iostream>

class Base
{
	private:
		Base() { std::cout << "Base\n"; }
		~Base() { std::cout << "~Base\n"; }
		friend class Deriv_final;
};

class Deriv_final : virtual Base // virtual by bezpośrednio wywoływało konstruktor klasy bazowej (błąd kompilajci) a nie normalnie przez klasę pośrednią
{
public:
	Deriv_final() { std::cout << "Deriv\n"; }
	~Deriv_final() { std::cout << "~Deriv\n"; }
};
class Deriv : public Deriv_final
{

};

	



int main()
{
	Deriv_final a;

	return 0;
}