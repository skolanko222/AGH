#include <iostream>
#include <cassert>
 
int main()
{
    assert(2+2==4);
    std::cout << "After first assert\n";

    assert(2+2==5);
    std::cout << "After second assert\n";
}