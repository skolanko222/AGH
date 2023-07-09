//2021 1 termin 2

#include<iostream>
#include<array>
#include<string>
#include <memory>
void my_print_el(std::string prefix){
    std::cout<<prefix;
}

using  arr_uniq_2 =  std::array<std::unique_ptr<int>,2>;
using uniq_int = std::unique_ptr<int>;

void my_print(arr_uniq_2& arr, std::string a, std::string b ){
    std::cout<<"[";
    for( auto &el: arr){
        std::cout<<*el<<a;
    }    
    std::cout<<"] "<<b<< " ";
}

void my_print(arr_uniq_2& arr ){
    std::cout<<"[";
    for( auto &el: arr){
        std::cout<<*el<<";";
    }    
    std::cout<<"] "<< "\n ";
}

void my_swap(uniq_int& a, uniq_int& b){
    std::swap(a, b);
}

void my_swap(int& a, int& b){
    std::swap(a, b);
}

// nienawidze cpp, jak kurwa pisac na kartce aaaaaaaaaaaa
int main()
{
  std::array<std::unique_ptr<int>,2> a = {
      std::unique_ptr<int>(new int {1}),
      std::unique_ptr<int>(new int {2})
      };

  my_print_el("----------------\n");
  my_print(a,";"," -> ");
  my_swap(a[0],a[1]);
  my_print(a,";"," -> ");
  my_swap(*a[0],*a[1]);
  my_print(a);
  my_print_el("----------------");
}
//[1;2;] -> [2;1;] -> [1;2;]


// 2 wersja troche lepsza i bez vecrtora

// #include<iostream>
// #include<array>
// #include<memory>

// void my_print_el(std::string s){
//     std::cout << s;
// }

// void my_print(std::array<std::unique_ptr<int>,2>& arr, std::string sep, std::string next){
//     std::cout << "[" << *arr[0] << sep << *arr[1] << "]" << next;
// }

// void my_print(std::array<std::unique_ptr<int>,2>& arr){
//     std::cout << "[" << *arr[0] << ";" << *arr[1] << "]\n";
// }

// template <typename T>
// void my_swap(T& x, T& y){
//     std::swap(x,y);
// }

// void my_swap(std::unique_ptr<int>& x, std::unique_ptr<int>& y){
//     std::swap(x,y);
// }

// void my_swap(int& x, int& y){
//     int temp = x;
//     x = y;
//     y = temp;
// }

// int main()
// {
//   std::array<std::unique_ptr<int>,2> a = {
//       std::unique_ptr<int>(new int {1}),
//       std::unique_ptr<int>(new int {2})
//       };

//   my_print_el("----------------\n");
//   my_print(a,";"," -> ");
//   my_swap(a[0],a[1]);
//   my_print(a,";"," -> ");
//   my_swap(*a[0],*a[1]);
//   my_print(a);
//   my_print_el("----------------\n");
// }
// //[1;2;] -> [2;1;] -> [1;2;]
