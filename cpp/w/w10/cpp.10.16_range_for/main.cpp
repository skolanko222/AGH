#include <iostream>
#include <vector>
 
int main() 
{
    for(int n: {-1, 0, 1, 2, 3, 4, 5}) // the initializer may be a braced-init-list
        std::cout << n << ' ';
    std::cout << "\n----------------------\n";

    int a[] = {0, 1, 2, 3, 4, 5};
    
    for(int n: a)  // the initializer may be an array
        std::cout << n << ' ';
    std::cout << '\n';

    for(int n: a)
    		++n;

    for(int n: a)
        std::cout << n << ' ';
    std::cout << '\n';

    for(int& n: a)
    		++n;

    for(int n: a) 
        std::cout << n << ' ';
    std::cout << "\n----------------------\n";

    std::vector<int> v = {2, 3, 4, 5, 6, 7};
 
    for(const int &i : v) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';
 
    for(auto i: v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';
 
    for(auto&& i: v){ // access by reference, the type of i is int&
        i+=1;
        std::cout << i << ' ';}
    std::cout << '\n';
}