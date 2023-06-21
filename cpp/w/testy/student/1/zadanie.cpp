#include <iostream>

struct A {
  A(/* U1 */)/* U2 */{}
  char _c;
};

struct X /* U3 */{
  X(char c, int i):/* U4 */{}
  int _i;
};

struct Y /* U5 */{
  Y(char c,double d ):/* U6 */{}
  double _d;
};

struct Z /* U7 */ {
  Z(char c, int i, double d)/* U8 */{}
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