#include <iostream>
#include <utility>

// template<typename T=float>
// struct Type_t{
//     friend std::ostream & operator<<(std::ostream & out, const Type_t<T> & obj){
//         return out << obj._v;
//     }
//     Type_t()=default;
//     explicit Type_t(T v):_v(v){std::cout << _v << "\n";}

//     T _v;
// };

// template<typename T>
// struct ptr{

//     using value_type=T;
//     explicit ptr(T *data):_data(data){}
//     ptr()=default;
//     T & operator*()const{
//         return *_data;
//     }
//     T* operator->()const{
//         return _data;
//     }
//     ptr(ptr<T>&&other){_data=other._data;other._data=nullptr;std::cout << __PRETTY_FUNCTION__<<"\n";}
//     ptr<T>&operator=(ptr<T>&&other){
//         if(this!=&other){
//             _data=other._data;
//             other._data=nullptr;
//             std::cout << __PRETTY_FUNCTION__<< "\n";
//         }
//         return *this;
//     }

//     ~ptr(){delete _data;}

//     private:
//     T *_data;
// };

//kawka
/* Uzupelnij 1 */
// template <typename T = float>
// struct Type_t
// {
//     T _v;
//     Type_t(T arg = T{}) : _v(arg){};
//     Type_t<T> & operator=(T) = delete;
//     friend std::ostream &operator<<(std::ostream &stream, const Type_t<T> &obj)
//     {
//         return stream << obj._v;
//     }
// };

// template <typename T>
// struct ptr
// {
//     T *_v;
//     using value_type = T;
//     ptr() { _v = nullptr; };
//     explicit ptr(T *obj) : _v(obj) {}
//     ptr(ptr<T> &&other)
//     {
//         _v = other._v;
//         other._v = nullptr;
//     }

//     ptr(const ptr &other) = delete;
//     ptr<T> &operator=(const ptr &other) = delete;

//     ptr<T> &operator=(ptr &&other)
//     {
//         _v = other._v;
//         other._v = nullptr;
//         return *this;
//     }

//     T *operator->() const
//     {
//         return _v;
//     }

//     T &operator*() const
//     {
//         return *_v;
//     }
// };
template<typename T = float>
struct Type_t
{
	Type_t() : _v(T{}) {}
	// Type_t(int x) : _v(x){} //to źle / nie potrzeba
	explicit Type_t(const T x ) : _v(x){} //  default value albo konstruktor Type_t()
	// friend std::ostream & operator<<(std::ostream & os,const Type_t& t)
    // {
    //     return os<<t._v;
    // }
    T _v;
};

std::ostream & operator<<(std::ostream & os,const Type_t<float>& t)
{
    return os<<t._v;
}
using Float_t = Type_t<>;
template<typename T >
class ptr
{
	public:
		using value_type = T;
		explicit ptr(T * a ) : data(a) {}
		ptr() {};
		// ptr(const ptr & a ) = delete;
		// ptr & operator=( ptr & a) = delete;
		ptr(const ptr && a) : data(std::move(a.data)) {};
		ptr & operator=(ptr&& a) {data = std::move(a.data); a.data = nullptr; return *this;};
		T& operator*() const{ //brak constów
        return *data;
		}
		T* operator->() const{ //brak constów
			return data;
		}
	private:
		T * data;

};


int main()
{
    using Test_t = ptr<std::pair<Float_t, Float_t>>;

    Test_t t1{new Test_t::value_type{}};
    // Test_t t2 = t1;                            // BLAD KOMPILACJI
    // Test_t t3; t3 = t1;                        // BLAD KOMPILACJI
    // Test_t t4 = new Test_t::value_type();      // BLAD KOMPILACJI

    (*t1).first = Test_t::value_type::first_type{1}; // Type_t<>(1)
    t1->second = Test_t::value_type::second_type{3.141};

    Test_t t2;
    t2 = std::move(t1);
    std::cout << (*t2).first << ", " << t2->second._v << "\n";

    const Test_t t3 = std::move(t2);
    // (*t3).first = 13;       //  BLAD KOMPILACJI
    // t3->second = 13;        //  BLAD KOMPILACJI

    std::cout << (*t3).first._v << ", " << t3->second << "\n";
}
/* output:
1, 3.141
1, 3.141
*/