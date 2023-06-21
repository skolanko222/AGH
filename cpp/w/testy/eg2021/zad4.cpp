#include <iostream>
#include <array>

template <typename T,typename V>
void set_for_each(T& cnt, V val) {
    for(auto v: cnt)
        v = val;
}

template <typename T>
void printer(const T& cnt, std::ostream& o = std::cout) {
    for(auto v: cnt)
        o << v << ";";
}

int main() {
    std::array<int, 5> t = {1,2,3};
    set_for_each(t,7);
    printer(t);
}