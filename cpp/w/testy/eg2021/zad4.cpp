#include <iostream>
#include <array>
#include <functional>

template <typename T,typename V>
void set_for_each(T& cnt, V val) {
    for(int& v: cnt)
        v = val;
}

template <typename T>
void printer(const T& cnt, std::ostream& o = std::cout) {
    for(auto v: cnt)
        o << v << ";";
}

int main() {
    int a1 = 1;
    int a2 =2;
    int a3 = 3;
    int ref1 = std::ref(a1);
    int ref2 = std::ref(a2);
    int ref3 = std::ref(a3);
    std::array<int, 3> t = {a1,a2,a3};
    std::array<std::reference_wrapper<int>, 3> v = {std::ref(a1),std::ref(a2),std::ref(a3)};
    //set_for_each(t,3);
    set_for_each(v,3);
    std::cout<<a1<<","<<a2<<","<<a3<<std::endl;
    std::cout<<ref1<<","<<ref2<<","<<ref3<<std::endl;
}