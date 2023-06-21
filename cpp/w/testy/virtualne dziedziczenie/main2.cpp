#include <iostream>

class S {
public:
  S() { std::cout << "S "; }
  virtual ~S() { std::cout << "~S "; }
};

class A : public S  {
public:
  A() { std::cout << "A "; }
  virtual ~A() { std::cout << "~A "; }
};
class B :public A   {
public:
  B()  { std::cout << "B "; }
  virtual ~B() { std::cout << "~B "; }
};

class C : virtual A {
public: 
  C()  { std::cout << "C "; }
  virtual ~C() { std::cout << "~C "; }
};

class D : public B, virtual public C {
public:
  D() { std::cout << "D\n"; }
  virtual ~D() { std::cout << "~D "; }

};

int main(){
D d;
}
