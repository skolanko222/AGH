#include <deque>
#include <iostream>
#include <memory> // std::allocator

template<class T = int,
   	  template <typename ElemType, typename AllocType> class StorageType = std::deque> // domyslne parametry takie a nie inne bo inaczej nie powiedzie sie uzycie konstruktora kopiujacego w main (inne parametry == niezgodnosc typow)
//patrz podrozdzial template template parameters w https://en.cppreference.com/w/cpp/language/template_parameters
class fifo {
    StorageType<T, std::allocator<T> > _cont; //dopiero od c++ 11 można >> zamiast > > xD
public:
    //using storage_type = decltype(_cont); // c++11
    typedef StorageType<T, std::allocator<T> > storage_type;
    fifo() {
   	 std::cout << __PRETTY_FUNCTION__ << std::endl; //tylko gcc, mozna uzyc typeid z naglowka typeinfo ale wyglada jak szit
    }

    unsigned size() const {
   	 return _cont.size();
    }

    T get() {
   	 T tmp = _cont.front();
   	 _cont.pop_front();
   	 return tmp;

    }

    typename storage_type::const_iterator begin() const { // kiedy uzywac nalezy slowka typename patrz w https://stackoverflow.com/questions/7923369/when-is-the-typename-keyword-necessary
   	 return _cont.begin();
    }

    auto end() const {
   	 return _cont.end();
    }

    void push(const T val) {
   	 _cont.push_back(val);
    }

};

// plik main.cpp
namespace std { class queue{}; }

int main()
{
	fifo<> ft;
	for(int i: {0,1,2,3,4,5,6,7,8,9}) // c++11, zakresowy for pracujacy na kopiach
    	ft.push(i);

	fifo<int, std::deque> f = ft;

	std::cout << f.get() << "\n";
	std::cout << f.size() << "\n";

	for(fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i) //tu juz nie trzreba typename, patrz link wyzej
    	std::cout << *i << ",";
	using pointer = void (*)(char);
	return 0; 
}
