#include <iostream>

class S {
public:
  S() { std::cout << "S "; }
  virtual ~S() { std::cout << "~S "; }
};

class A : public S {
public:
  A() { std::cout << "A "; }
  virtual ~A() { std::cout << "~A "; }
};

class B : public A {
public:
  B() : A() { std::cout << "B "; }
  virtual ~B() { std::cout << "~B "; }
};

class C : virtual public A {
public:
  C() : A() { std::cout << "C "; }
  virtual ~C() { std::cout << "~C "; }
};

class D : public C, virtual public B {
public:
  D(): B(), C() { std::cout << "D\n"; }
  virtual ~D() { std::cout << "~D "; }
protected:
  C c;
};

int main(){
D d;
}
