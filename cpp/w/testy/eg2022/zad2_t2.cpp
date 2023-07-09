#include <iostream>
template<typename T>
class B{
	T data;
	public:
		B(T a) : data(a) {}
		B(const B<T> & obj) : data(obj.data) {}
		T & get() {return data;}

};
template<typename T>
class B<T*>{
	T * data;
	public:
		B( T * obj) : data(obj) {}
		using value_type = T;
		B(const B<T*> &obj) = delete;
		B<T*> & operator=(const B<T*> & obj) const = delete;
		T & get() {return *data;}

};

// template<>
// class B<int *>{
// 	int * data;
// 	public:
// 		B( int * obj) : data(obj) {}
// 		using value_type = int;
// 		B(const B<int*> &obj) = delete;
// 		B<int*> & operator=(const B<int*> & obj) const = delete;
// 		int & get() {return *data;}

// };
int main()
{
    typedef B<int> int_b;
    typedef B<int*> int_p_b;        //jednak typedef

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    // int_p_b e = b; //error
    // b=b //error
    
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout <<" b=" << b.get()+1 << std::endl;
}