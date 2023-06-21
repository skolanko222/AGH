#include <iostream>

struct A{
    A() : A{0} {
        std::cout<< "A();\n";
    }

    A(const A& a): A(a._a) {
        std::cout << "A(const A&);\n";
    }

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
    A a; 
    a = A{};

}