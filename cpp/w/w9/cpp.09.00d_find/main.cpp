// https://en.cppreference.com/w/cpp/algorithm/find
#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

 
int main()
{
    int n1 = 3;
    int n2 = 5;
 
    // int v1[] = {0, 1, 2, 3, 4};
    // std::vector<int> v1{0, 1, 2, 3, 4};
    std::array<double, 5> v1{0, 1, 2, 3, 4};
 
    auto result1 = std::find(std::begin(v1), std::end(v1), n1);
    auto result2 = std::find(std::begin(v1), std::end(v1), n2);
 
    if (result1 != std::end(v1)) {
        std::cout << "v1 contains: " << *result1 << '\n';
    } else {
        std::cout << "v1 does not contain: " << n1 << '\n';
    }
 
    if (result2 != std::end(v1)) {
        std::cout << "v1 contains: " << n2 << '\n';
    } else {
        std::cout << "v1 does not contain: " << n2 << '\n';
    }
}
