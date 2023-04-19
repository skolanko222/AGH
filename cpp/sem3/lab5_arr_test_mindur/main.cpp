#include <iostream>

#include "DynamicArray.h"

using namespace std;    

int main()
{

    DynamicArray arr;
    //cout << arr.size() << endl;
    arr.add(1, 10);
    arr.add(2, 12);
    arr.add(3, 19);
    arr.add(4, 20);
    arr.print();
    arr.size();
    cout << arr.get(21) << endl;

    return 0;
}