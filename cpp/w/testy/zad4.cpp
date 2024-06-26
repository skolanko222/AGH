namespace oop
{
    template <typename T>
    class Array
    {
		public:
        T* tab;
        int size;
    public:
        typedef char value_type;
        explicit  Array (int maxsize):tab(new T[maxsize]){};
        Array& insert(T el){tab[size]=el;size++;return *this;};
        Array& operator + (T el){return insert(el);}
        int operator~(){return size;}
        T operator [](unsigned i){return tab[i];}
    };
}



namespace std {class vector{}; class list{}; class deque{}; class set{}; class map{};   }
#include <cstdlib>
#include <iostream>
int main()
{

    typedef oop::Array<char> type;
    type a = type{10};
	type b( 10);

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3 );
	std::cout << b.size;
    for(unsigned i = 0; i!= ~a; ++i)
    {
        std::cout<< a[i] << (i+1 != ~a ? "" : "\n"  );
    }

}

