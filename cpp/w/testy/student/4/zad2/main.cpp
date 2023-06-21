#include<iostream>

class Base {
    public:
    typedef double func;
};

//

//Jakie dwa szablony funkcji trzeba napisać żeby kod zgodnie z zasadą SFINAE kompilował się poprawnie?
//Szablony powinny wypisywać napis "szablon " i numer szablonu


//pierwszy szablon
template <typename T>
void f(typename T::func obj) {
  std::cout<<"szablon 1"<<std::endl;
}

//drugi szablon
template <typename T>
void f(T obj) {
  std::cout<<"szablon 2"<<std::endl;
}





int main() {
  f<Base>(10.0);  // szablon 1 ma zostać użyty
  f<double>(10.0);   // tutaj ma zostać użyty szablon 2
  return 0;
}








































