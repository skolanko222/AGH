#include <iostream>
#include <vector>
#include <typeinfo>
 
int main()
{

    std::vector<double> a1 = {1, 2, 3};  // never required after =

    using vector_int_t = std::vector<double>;
    vector_int_t a2 = {};  // never required after =

    a2 = a1; //OK

    std::cout << "a1\t" << typeid(a1).name() << "\n";
    std::cout << "vector_int_4_t::value_type\t" << typeid(vector_int_t::value_type).name() << "\n";

    // ranged for loop is supported
    for(const auto& s: a2)
        std::cout << s << ' ';
    std::cout << "    " << a2.size() << '\n';

    a2.push_back(11);
    a2.push_back(12);
    a2.push_back(13);
    std::cout << "    " << a2.size() << '\n';
    for(const auto& s: a2)
        std::cout << s << ' ';
    std::cout << '\n';

    a2.pop_back();
    a2[1] = a2[3];
    for(const auto& s: a2)
        std::cout << s << ' ';
    std::cout << '\n';

}