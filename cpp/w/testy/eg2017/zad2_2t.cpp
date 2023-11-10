namespace oop
{

    template <typename T>
    class Array
    {
        T* tab;
        static int size;
    public:
        typedef char value_type;
        Array (int maxsize):tab(new T[maxsize]){};
        Array& insert(T el){tab[size]=el;size++;return *this;};
        Array& operator + (T el){return insert(el);}
        int operator~(){return size;}
        T operator [](unsigned i){return tab[i];}
    };
    template <typename T>
    int Array<T>::size=0;
}



namespace std {class vector{}; class list{}; class deque{}; class set{}; class map{};   }
#include <cstdlib>
#include <iostream>
int main()
{

    typedef oop::Array<char> type;
    type a( rand() % 10 + 6 );

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3 );

    for(unsigned i = 0; i!= ~a; ++i)
    {
        std::cout<< a[i] << (i+1 != ~a ? "" : "\n"  );
    }

}