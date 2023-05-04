#include <iostream>

using namespace std;

class MyException
{
public:
  virtual void print()
  {
  }
};

/////////////////////////////////////////////////////////////////////////
class MyExceptionFloat : public MyException
{
public:
  MyExceptionFloat(float ff = 0.0) : f(ff)
  {
  }
  void print()
  {
    cout << f;
  }
  float f;
};

/////////////////////////////////////////////////////////////////////////
class MyExceptionInt : public MyException
{
public:
  MyExceptionInt(int ff = 0) : f(ff)
  {
  }
  void print()
  {
    cout << f;
  }

  int f;
};

/////////////////////////////////////////////////////////////////////////
class MyExceptionChar : public MyException
{
public:
  MyExceptionChar(char ff = 'a') : f(ff), test(10)
  {
  }
  void print()
  {
    cout << f;
  }

  char f;
  int  test;
};

/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
  try
  {
    try
    {
      int a;

      cout
          << "Podaj rodazaj wyrzucenia wyjatku\n1 - int, 2 - float, 3 - char\n";
      cin >> a;

      if (a == 1)
        throw MyExceptionInt(10);
      else if (a == 2)
        throw MyExceptionFloat(25.36);
      else if (a == 3)
        throw MyExceptionChar();
      else
      {
        MyExceptionFloat *ptr = new MyExceptionFloat(3.14);
        throw ptr;
      }
    }
    catch (MyExceptionInt &K)
    {
      cout << "Zlapany wyjatek MyExceptionInt = " << K.f << "\n";
      return -1;
    }
    catch (MyExceptionFloat &K)
    {
      cout << "Zlapany wyjatek MyExceptionFloat = " << K.f << "\n";
      return -1;
    }
    catch (MyException &K)
    {
      cout << "\nZlapany wyjatek klasy podstawowej\n";
      throw;
    }
  }

  catch (MyExceptionChar &K)
  {
    cout << "Zlapany wyjatek MyExceptionChar& = ";
    K.print();
    cout << ", zmienna dodatkowa test = " << K.test << endl;
    return -1;
  }
  catch (MyException *K)
  {
    cout << "Zlapany wyjatek MyException* = ";
    K->print();
    cout << endl;
    return -1;
  }

  cout << "Program zadzialal poprawnie\n";
  return 0;
}
