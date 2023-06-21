#include <iostream>

template<typename T>
struct box{
    T a_ = {};
};

template<typename T>
std::ostream& operator<<(std::ostream& o, const box<T>& val) {
    return o<<"T("<< val.a_<<");";
}

int main() {
    std::cout<< box<box<int>>() << std::endl;
}