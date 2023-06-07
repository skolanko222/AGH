#include <iostream>
using std::cout;
struct A {
  virtual void foo() const 
  {cout << __PRETTY_FUNCTION__ << "\n";}
  void bar()
  {}
};

struct B : public A {
  void foo() const override
  {cout << __PRETTY_FUNCTION__ << "\n";}
  virtual void fin()  const final
  {cout << __PRETTY_FUNCTION__ << "\n";}
};

struct C1 : public B {
//   void fin() const override {} error: virtual function ‘virtual void C1::fin() const’ overriding final function

};

struct C2 final : public B {
	void foo() const override 
	{cout << __PRETTY_FUNCTION__ << "\n";}

};

// struct D : C1 {}; error: cannot derive from ‘final’ base ‘C2’ in derived type ‘D’
int main(int argc, char *argv[]) {
	A a; // base class
	B b;
	C1 c1;
	C2 c2;
	A * ptr = &c1; 
	ptr->foo(); // B::foo()
	ptr = &c2; 
	ptr->foo(); // B::foo()

}
