#include <iostream>

struct A{
    A() : A{0} {
        std::cout<< "A();\n";
    }

    A(const A& a): A(a._a) {
        std::cout << "A(const A&);\n";
    }
    A operator=(const A &&a){std::cout << __PRETTY_FUNCTION__;}
    A operator=(const A &a){std::cout << __PRETTY_FUNCTION__;}
    A(int a) : _a(a) {
        std::cout<< "A(int);\n";
    }
    ~A() {
        std::cout<< "~A();\n";
    }
    private:
    int _a=0;
};

int main() {
     
    A a = A{};

}