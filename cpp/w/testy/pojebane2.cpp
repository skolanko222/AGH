#include <utility>
#include <iostream>


template<typename T = float>
struct Type_t
{
    Type_t() = default;
    explicit Type_t(T x) : _v(x){}
    friend std::ostream & operator<<(std::ostream & os,const Type_t& t)
    {
        return os<<t._v;
    }
    T _v;
};

using Float_t = Type_t<>;

template<typename T>
class ptr{
    public:
    using value_type = T;
    ptr(T* t): data(t){}
    ptr(ptr<T>&& t): data(std::move(t.getdata())){}
    ptr(const ptr<T>&) = delete;
    ptr<T>& operator=(const ptr<T>&) = delete;
    ptr<T>& operator=(const ptr<T>&&) = delete;
    T& operator*()const{
        return *data;
    }
    T* operator->()const{
        return data;
    }
    T* getdata()const{
        return data;
    }
    private:
    T* data;
};

int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>; //

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t2; t2 = t1;
    Type_t t22 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.}; //ptr<std::pair<Type_t<>,Type_t<>>::T::first_type
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);

    // t3=std::move(t2); 
    const Type_t t3{new Type_t::value_type{}};                                 // tutaj było chyba const t3, ale nie pamiętam, w jaki sposób było inicjalizowane
                                                       //(*t3).first= 13;
                                                       t3->second = 13;
                                                       // Powyższe się mają nie kompilować
    (*t3).first = Type_t::value_type::first_type{1};   //?
    t3->second = Type_t::value_type::second_type{2.5}; //?

    
    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
*/