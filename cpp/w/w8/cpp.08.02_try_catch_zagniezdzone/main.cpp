#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////
void fun1()
{
  int a, b(0);
  cout << "Podaj liczbe dodatnia = ";
  cin >> a;
  if (a <= 0)
    throw b;
}
/////////////////////////////////////////////////////////////////////////
void fun2()
{
  char a;
  cout << "Podaj znak [a-d] = ";
  cin >> a;
  if ((int)(a) > (int)('d') || (int)(a) < (int)('a'))
    throw a;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

  try
  {
    cout << "Wywolanie fun1, ktora mo¿e zadzialac zle\n";
    fun1();
    cout << "Wywolanie fun2 ktora mo¿e zadzialac zle\n";
    fun2();

    int i = 0;
    while (true)
    {
      try
      {
        cout << "Podaj liczbe podzielna przez 10 = ";
        int a;
        cin >> a;
        ++i;
        if (a % 10 != 0)
          throw(float)(a % 10);
        else
          break;
      }
      catch (const float f)
      {
        cout << "Reszta z dzielenia = " << f << endl;
        cout << "Liczba nie jest podzialena przez 10\n";
        if (i > 2)
          throw(int)(f);
        else
          cout << "Sprobuj jeszcze raz\nPodaj liczbe = ";
      }
    }
  }
  catch (const int)
  {
    cout << "Zlapany wyjatek int\n";
    return -1;
  }
  catch (const char &a)
  {
    cout << "Zlapany wyjatek char\n";
    cout << "Znak jaki przes³a³a: " << a << endl;
    return -1;
  }
  cout << "Program zadzialal poprawnie\n";
  return 0;
}
