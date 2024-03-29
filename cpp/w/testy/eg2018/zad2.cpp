#include <iostream>
#include <deque>

// template<typename T = int, typename StorageType = std::deque > źle
template<typename T = int, 
                         template <typename T2 = T, typename AllocType = std::allocator<T>> 
                                                                    typename StorageType = std::deque >
class fifo {
    public:
    using storage_type = StorageType<T,std::allocator<T>>;

    fifo() {
        std::cout << __PRETTY_FUNCTION__ << "\n";
    }
    void push(const T & v) {
        _storage.push_back(v);
    }

    T get() {
        T tmp = _storage.front();
        _storage.pop_front();
        return tmp;
    }

    size_t size() const {
        return _storage.size();
    }

    auto begin() const { // https://stackoverflow.com/questions/1600936/officially-what-is-typename-for
        return _storage.begin();
    }

    auto end() const { // typename gwarantuje ze to jest typ klasy storage_type a nie zmienna
        return _storage.end();                          // https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
    }
    private:
        storage_type _storage; // ja pierdole
        // StorageType<T> _storage;
};
int main()
{
    fifo<> ft;
    for(int i : {0,1,2,3,4})
   	 ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << f.size();

    for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
   	 std::cout << *i << ",";
}



// fifo<T, StorageType>::fifo() [with T = int, StorageType = std::deque]
// 0
// 4
// 1,2,3,4,