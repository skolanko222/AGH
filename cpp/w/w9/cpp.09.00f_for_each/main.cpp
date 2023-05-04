#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <functional>
 
struct sum
{
    void operator()(int n) { sum += n; }
    int sum{0};
};

struct print
{
    void operator()(const std::string& s) { std::cout << "[" << s << "] "; }
};
 
struct to_upper
{
    void operator()(std::string& s) { 
        for(auto& c : s) 
            c = std::toupper(c);
    }
};

int main()
{
    std::vector<int> nums = {3, 4, 2, 8, 15, 267};
    sum sum1;

    std::for_each(nums.begin(), nums.end(), std::ref(sum1));
    std::cout << "Suma: " << sum1.sum << '\n';

    std::vector<std::string> strs{"Raz", "dwa", "trzy", "Ala ma kota"};

    std::for_each(std::begin(strs), std::end(strs), print());
    std::cout << "\n";

    std::for_each(std::begin(strs), std::end(strs), to_upper());
    std::for_each(std::begin(strs), std::end(strs), print());
    std::cout << "\n";

}