#include <iostream>
#include <vector>
#include <initializer_list>
 
struct S {
    std::vector<int> v;
    S(std::initializer_list<int> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<int>&& l) {
        v.insert(v.end(), l.begin(), l.end());
    }

};

int main()
{
	S ss {1};
    S s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append({6, 7, 8});      // list-initialization in function call

    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';
 	 
    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';
 
}