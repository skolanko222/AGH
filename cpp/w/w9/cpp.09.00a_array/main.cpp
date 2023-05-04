#include <iostream>
#include <array>
#include <typeinfo>
 
int main()
{

    // construction uses aggregate initialization
    std::array<int, 3> a1{ {1, 2, 3} }; // double-braces required in C++11 prior to the CWG 1270 revision
                                        // (not needed in C++11 after the revision and in C++14 and beyond)
    std::array<int, 3> a2 = {1, 2, 3};  // never required after =

    using array_int_4_t = std::array<int, 4>;
    array_int_4_t a3 = {1, 2, 3};  // never required after =

    a1 = a2; //OK
    // a1 = a3; //Compile error

    std::cout << "a1\t" << typeid(a1).name() << "\n";
    std::cout << "a3\t" << typeid(a3).name() << "\n";
    std::cout << "array_int_4_t::value_type\t" 
    << typeid(array_int_4_t::value_type).name() << "\n";

    // ranged for loop is supported
    for(const auto& s: a3)
        std::cout << s << ' ';
}
