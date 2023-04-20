#include <iostream>
#include "silnia.h"

int main(int argc, char *argv[])
{
    int m,n;
    if(argc > 1)
    {
        m = atoi(argv[1]);
        n = atoi(argv[2]);

    }
    int wynik = dwumian(m,n);
    if(wynik < 0)
    {
        std::cout << "Argumenty niepoprawne!";
        return -1;
    }
    std::cout << "Dla m = " << m << " n = " << n << " wynik = " << wynik << std::endl;
    
    return 0;
}