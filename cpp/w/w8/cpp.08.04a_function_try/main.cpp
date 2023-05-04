#include <iostream>
#include <string>

struct S {
    std::string m;

    S(const std::string& arg) try : m(arg, 100) {
        std::cout << "constructed, mn = " << m << '\n';
    } catch(const std::exception& e) {
        std::cout << "arg=" << arg << " failed: " << e.what() << '\n';
    } // implicit throw; here
};


int f(int n = 2) try {
   ++n; // increments the function parameter
   throw n;
}
catch(...) {
   ++n; // n is in scope and still refers to the function parameter
   std::cout << "Value n still reachable = " << n << '\n';
    return n;
}

int main()
{
    f();
    try {
        S s("Test");
    }
    catch(const std::exception& e) {
       std::cout << "Catch rethrown exception from S::S()\n" << e.what() << '\n';
    }
}