#include <string>
#include <iostream>
#include <typeinfo>
 
int main()
{
    std::cout << "std::string --> " << typeid(std::string{}).name() << "\n";

    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin, name); // read a full line of text into name
 
    std::cout << "Enter your age: ";
    std::string age{};
    std::getline(std::cin, age); // read a full line of text into age
 
    int age_int = std::stoi(age) + 1;

    std::cout << "\nYour name is " << name << " and your age is " + std::to_string(age_int) + "\n";
}