#include <iostream>

int main()
{

    std::string str1 = "123 ";
    std::string str2 = "456";

    std::string str3 = str1 + str2;
    std::string::iterator it;
    for(it=str3.begin(); it!=str3.end(); ++it){
        std::cout << *it;
    }
    std::cout << std::endl << str3.length();
    str3.pop_back();
    std::cout << std::endl << str3.length();
    str3.push_back('l');
    std::cout << std::endl << str3;
    
    return 0;
}