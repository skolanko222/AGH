#include <iostream>
#include <vector>
#include <memory>

//napisz głosne konstruktory i operatory: kopiujący konstruktor robiący głeboką kopie, 
//przenoszący konstruktor, operator przypisania i destruktor
//żeby program się kompilował

class Base
{
private:
    std::vector<std::shared_ptr<int>> v;
public:
    Base(const std::initializer_list<std::shared_ptr<int>> &l): v{l}{};
    //w tym miejscu dopisz potrzbny kod 
    // Base(const Base &o){
    //     std::cout<<"Konstruktor kopiujący"<<std::endl;
    //     for(auto &i: o.v){
    //         v.push_back(std::make_unique<int>(*(i.get())));
    //     }
    // } 
    // Base(Base &&o){
    //     std::cout<<"Konstruktor przenoszący"<<std::endl;
    //     for(auto &i: o.v){
    //         v.push_back(std::move(i));
    //     }
       
    // }
    // Base& operator=(const Base &o){
    //     std::cout<<"operator przypisania"<<std::endl;
    //     if(&o==this){
    //         return *this;
    //     }
    //     v.clear();
    //     for(auto &i: o.v){
    //         v.push_back(i);
    //     }
    //     return *this;
    // }
    // ~Base(){
    //     std::cout<<"Destruktor"<<std::endl;
    // }

    
    void print()const{
        for(auto &i : v){
            std::cout<<i.get()<<std::endl;
        }
    } 
};
int main(){
    auto a = std::make_shared<int>(1);
    auto b = std::make_shared<int>(2);
    auto c = std::make_shared<int>(3);
    Base A{a,b,c};
    Base B{A};
    A.print();
    B.print();
    Base C{std::move(A)};
    A.print();
    C.print(); 
    A=C;
    A.print();
}




































   
