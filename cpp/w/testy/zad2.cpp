#include <type_traits> // Dla std::is_pod i std::integral_constant 
#include <iostream>
#include <deque>
#include <vector>


struct A {};
struct A_ { virtual ~A_() {} };

template<bool T>
struct Is_Pod{
    static void print(){
        std::cout<<"Copying POD objects"<<std::endl;
    }
};

template<>
struct Is_Pod<false>{
    static void print(){
        std::cout<<"Copying Non-POD objects"<<std::endl;
    }
};

template<typename T,typename T1>
void my_copy(T begin, T end, T1 copybegin){
    Is_Pod<std::is_pod<typename T::value_type>::value>::print();
}

int main()  {
//prosze wykorzystac te informacje
std::integral_constant<bool,true> tA = std::is_pod<A>::type();
std::integral_constant<bool,false> tA_ = std::is_pod<A_>::type();

//Iterator dla każdego kontenera ma zdefiniowany 
//typ value_type określający typ obiektu na który wskazuje
std::deque<A> vA1;
std::vector<A> vA2;
my_copy(vA1.begin(), vA1.end(), vA2.begin() ) ;

std::vector <A_> vA_1;
std::deque<A_> vA_2;
my_copy(vA_1.begin(), vA_1.end(), vA_2.begin() ) ;
}
/* output/wyjscie 
Copying POD objects
Copying non-POD objects
*/
