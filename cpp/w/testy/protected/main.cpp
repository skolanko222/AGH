// C++ program to demonstrate
// protected access modifier
#include <bits/stdc++.h>
using namespace std;
  
// base class
class Parent {
public:
	int id_public;
	// protected data members
protected:
    int id_protected;
};
  
// sub class or derived class
class Child : protected Parent {
  
public:
    void setId(int id)
    {
  
        // Child class is able to access the inherited
        // protected data members of base class
  
        id_protected = id;
    }
  
    void displayId()
    {
        cout << "id_protected is: " << id_protected << endl;
    }
};
  
// main function
int main()
{
	Parent obj;
	// obj.id_protected = 1; BŁĄD
	obj.id_public = 1;
    Child obj1; 
	// obj1.id_public = 1; przy dziedziczeniu protected nie ma dostępu do public
	// obj1.id_protected = 1; BŁĄD
    // member function of the derived class can
    // access the protected data members of the base class
  
    obj1.setId(81);
    obj1.displayId();
    return 0;
}