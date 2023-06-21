#include <iostream>
class D{
    public:
    D(){
        std::cout<<"D";
    }
};
class A{
    public:
    A(){
        std::cout<<"A";
    }
};
class B: public A{
    D obj;
    public:
    B(): obj{}, A{} {
        std::cout<<"B";
    }
};
class C: public B{
    B obj;
    public:
    C(): B{}, obj{} {
        std::cout<<"C";
    }
};
int main(){
    std::cout<<"Result:\n";
    C obj{};
    std::cout<<std::endl;
}