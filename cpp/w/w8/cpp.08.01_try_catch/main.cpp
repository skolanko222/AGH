#include <iostream>

using namespace std;

void fun1()
{
  int a, b(0);
  cout << "Podaj liczbe >0 = ";
  cin >> a;
  if (a <= 0)
    throw b;
}

void fun2()
{
  char a;
  cout << "Podaj znak [a-d] = ";
  cin >> a;
  if ((int)(a) > (int)('d') || (int)(a) < (int)('a'))
    throw a;
}
/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

  try
  {
    cout << "Wywolanie fun1, ktora moze zadzialac zle\n";
    fun1();
    cout << "Wywolanie fun2 ktora moze zadzialac zle\n";
    fun2();
  }
  catch (int)
  {
    cout << "Funkcja fun1 wyrzucila wyjatek\n";
    return -1;
  }
  catch (const char &a)
  {
    cout << "Funkcja fun2 wyrzucila wyjatek\n";
    cout << "Znak jaki przeslala: " << a << endl;
    return -2;
  }
  cout << "Program zadzialal poprawnie\n";
  return 0;
}

