#include <iostream>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu
// użycie gdziekolwiek słowa kluczowego public oznacza 0 punktów za zadanie

struct B {
protected:
  // U1 - tylko deklaracje funkcji maks. 2
  virtual void printOn(std::ostream &o) const = 0;
  friend std::ostream &operator<<(std::ostream &o, const B & obj);
};
//  U2 - tylko definicje funkcji z U1
inline void B::printOn(std::ostream &o) const {o << __PRETTY_FUNCTION__ << "\n";};
std::ostream & operator<<(std::ostream &o, const B & obj) 
{
	obj.printOn(o);
	return o;
}

class D1 : public B {
protected:
  // U4 - tylko deklaracja albo definicja jednej funkcjiB() {};
  virtual void printOn(std::ostream &o) const override {o << __PRETTY_FUNCTION__ << "\n";};
};

struct D2 : public D1 {};

class D3 : public D1 {
protected:
  // U7 - tylko deklaracja albo definicja jednej funkcji
 
  virtual void printOn(std::ostream &o) const override {o << __PRETTY_FUNCTION__ << "\n";};
};

struct D4 : public D3 {;
protected:
//   // U9 - tylko deklaracja albo definicja jednej funkcji
//   D4() {};
	  virtual void printOn(std::ostream &o) const override 
	  { 
      B::printOn(o);
	  	D1::printOn(o);
	  	D3::printOn(o);
      
		o << __PRETTY_FUNCTION__ << "\n";	
		};
}; // */

int main(int argc, char *argv[]) {
  // B b; //odkomentowani  e powoduje błąd kompilacji
  D1 d1; D2 d2; D3 d3; const D4 d4;
  std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/* Output:
d1: [...] D1::printOn[...]
d2: [...] D1::printOn[...]
d3: [...] D3::printOn[...]
d4: [...] B::printOn[...]
[...] D1::printOn[...]
[...] D3::printOn[...]
[...] D4::printOn[...]
*/
