#include <iostream>

struct A {
  A(char c='Z'):_c(c){}
  char _c;
};

struct X: virtual A {
  X(char c, int i):_i(i), A(c) {}
  int _i;
};

struct Y: virtual A{
  Y(char c,double d ):_d(d), A(c){}
  double _d;
};

struct Z: X, Y {
  Z(const char &c, int i, double d):X(c,i), Y(c,d){}
};

int main(int argc, char *argv[]) {

  X x('X', 10); Y y('Y', 10.5); Z z('Z', 11, 11.2);
  std::cout<<x._c<<"  "<<x._i<</*"  "<<x._d<<*/"\n";//po odkomentowaniu błąd kompilacji
  std::cout<<y._c<<"  "<</*y._i<<"  "<<*/y._d<<"\n";//po odkomentowaniu błąd kompilacji
  std::cout<<z._c<<"  "<<z._i<<"  "<<z._d<<"\n";
}

/* Output:
X    10
Y    10.5
Z    11    11.2
*/
