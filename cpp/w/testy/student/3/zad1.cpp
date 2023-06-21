#include <iostream>
#include <utility>

struct A{
  A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //A::A()
  ~A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //A::~A()
};

struct B : public A{
  int _data;
  B() : A(){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //B::B()
  B(int data) : A(), _data(data){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //B::B(int)
  ~B(){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //B::~B()
};

struct C : public B{
  int _data;
  C() : B(){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //C::C()
  C(int data) : B(data), _data(data){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //C::C(int)
  C(const C& ref) : C(ref._data){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //C::C(const C&)
  C(C&& ref) : C(std::move(ref._data)){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //C::C(C&&)
  C& operator=(const C& ref){std::cout<<__PRETTY_FUNCTION__<<std::endl;return *this;} //C& C::operator=(const C&)
  C& operator=(C&& ref){std::cout<<__PRETTY_FUNCTION__<<std::endl;return *this;} //C& C::operator=(C&&)
  ~C(){std::cout<<__PRETTY_FUNCTION__<<std::endl;} //C::~C()
};

int main(){
  C c1;
  const C c2 = c1 = c1 = std::move(C(10));
  A* c = new C(std::move(c1));
  return 0;
}