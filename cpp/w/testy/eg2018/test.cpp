#include <iostream>
#include <deque>

// template<typename T = int, typename StorageType = std::deque > źle
template<typename T>
struct temp
{


};

int main()
{
    temp<std::pair<int,int>> ft;

    // for(int i: {0,1,2,3,4})
   	//  ft.push(i);

    // fifo<int, std::deque> f = ft;

    // std::cout << f.get();
    // std::cout << f.size();

    // for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
   	//  std::cout << *i << ",";
}



// fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
// 0
// 4
// 1,2,3,4,