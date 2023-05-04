#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
 
int main()
{
    using namespace std::placeholders;  // for _1, _2, _3...
    std::vector<int> v{ 1, 2, 3, 4, 4, 3, 7, 8, 9, 10 };
 
    int num_items3 = std::count_if(v.begin(), v.end(), 
        std::bind(std::greater<int>(), _1, 8));
    std::cout << "number bigger then 8: " << num_items3 << '\n';

    int num_items4 = std::count_if(v.begin(), v.end(), 
        std::bind(std::less<int>(), _1, 8));
    std::cout << "number less then 8: " << num_items4 << '\n';
}