#include<bits/stdc++.h>

struct A{
    A(){std::cout<<__PRETTY_FUNCTION__<<'\n';}
    A(const A& other){std::cout<<__PRETTY_FUNCTION__<<'\n';}
    virtual ~A(){ std::cout<<__PRETTY_FUNCTION__<<'\n';}
};

template<typename T>
struct B : A{
    T v = T{};
    B() { std::cout<<__PRETTY_FUNCTION__<<'\n'; };
    B(const B& b):v(b.v){
        std::cout<<"copy " << __PRETTY_FUNCTION__<<"()\n";
    }
    ~B(){
        std::cout<<"-"<<typeid(B<T>).name()<<"()\n";
    }
};
int main(){
    /*typedef B<A> B_A;
    using Typename = B<B_A>;*/

    B<B<A>> a = B<B<A>>(B<B<A>>(B<B<A>>(B<B<A>>()))); 
    B<B<A>> b(a);

    // Typename a = Typename(Typename()); //  B<B<A>> a = B<B<A>>(B<B<A>>())
    // Typename b(a);
    // B<A> v = B<A>() 
}
// A A B A A A B