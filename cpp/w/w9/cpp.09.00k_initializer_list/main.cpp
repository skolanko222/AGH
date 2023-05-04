// https://en.cppreference.com/w/cpp/utility/initializer_list

#include <iostream>
#include <vector>
#include <initializer_list>
 
struct S {
    std::vector<int> v;
    S(std::initializer_list<int> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<int> l) {
        std::cout << "append with a " << l.size() << "-element list\n";
        v.insert(v.end(), l.begin(), l.end());
    }

    size_t size() const{
        return v.size();
    }
};
 

int main()
{
    S s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append({6, 7, 8});      // list-initialization in function call
 
    std::cout << "The vector size is now " << s.size() << " ints:\n";
 
    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';
 
    std::cout << "Range-for over brace-init-list: \n";
 
    for (int x : {1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';
 
    auto al = {10, 11, 12};   // special rule for auto
 
    std::cout << "The list bound to auto has size() = " << al.size() << '\n';
 }
