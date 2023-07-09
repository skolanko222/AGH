#include <utility>
#include <iostream>


template<typename T = float>
struct Type_t
{
	explicit Type_t(T a) : _v(a) {}
	Type_t() = default;
    T _v;
};
template<typename T = float>
std::ostream & operator<<(std::ostream & o, const Type_t<T> & obj)
{
    return o << obj._v;
}

using Float_t = Type_t<>;

template<typename T>
class ptr{
    public:
    using value_type = T;
    explicit ptr(T * a) :data(a){}
	ptr(const ptr<T> & a) = delete; // ptr<T> czy ptr ?? 
    ptr(const ptr<T> && a) : data(std::move(a.data)){std::cout << "move" << std::endl;}
    T& operator=(const T && obj) = delete;
	T& operator=(const T & obj) = delete;
	T & operator*() const {return *data;};
	T *  operator->() const {return data;}; // (p.operator->())->m = 10

    private:
    T* data;
};

int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>; //

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t3; t3 = t1; // copy and =copt
    // Type_t t32 = new Type_t::value_type(); // explicit
    // Powyższe się mają nie kompilować
	(*t1).first = Type_t::value_type::first_type{1.}; // value_type = pair ==> first_type = Float_t
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);

    // t3=std::move(t2); 
    const Type_t t3{new Type_t::value_type{}};                                 // tutaj było chyba const t3, ale nie pamiętam, w jaki sposób było inicjalizowane
                                                    //    (*t3).first= 13;
                                                    //    t3->second = 13;
                                                       // Powyższe się mają nie kompilować
    (*t3).first = Type_t::value_type::first_type{1};   //?
    t3->second = Type_t::value_type::second_type{2.5}; //?

    
    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
*/