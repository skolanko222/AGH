#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>

using namespace std;


///////////////// Bad cast demonstration ////////////////////////////////
class Shape {
public:
   virtual void virtualfunc() const {}
};
/////////////////////////////////////////////////////////////////////////
class Circle: public Shape {
public:
   virtual void virtualfunc() const 
   {
   };
};

/////////////////////////////////////////////////////////////////////////
class MyException : public std::exception
{
public: 

	MyException(const std::string& what = "jakas przyczyna") : m_what(what)
	{}

	~MyException() throw()
	{}

	const char* what() const throw()
	{ return m_what.c_str(); }

private:
   std::string m_what;
};

/////////////////////////////////////////////////////////////////////////
void BadAlloc()
{
	double **p = new double*[100000000];
	for(long i = 0; i < 100000000; ++i)
		p[i] = new double[10000];
}

/////////////////////////////////////////////////////////////////////////
void BadCast()
{
	Shape shape_instance;
	Shape& ref_shape = shape_instance;
	Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);	

	ref_circle.virtualfunc();
}

/////////////////////////////////////////////////////////////////////////
void BadTypeid()
{
	Shape* K = NULL;
	typeid(*K).name();
}

/////////////////////////////////////////////////////////////////////////
void OutOfRange()
{
	string str( "Micro" );
  string rstr( "soft" );
  str.append( rstr, 5, 3 );
}

/////////////////////////////////////////////////////////////////////////
void RangeError()
{
	throw std::range_error( "Blad zakresu!" );
}

/////////////////////////////////////////////////////////////////////////
void IosBaseFailure()
{
   cout.exceptions( ios::eofbit );
	 cout.clear( ios::eofbit );
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
	for(;;)
	{
	try
	{
		cout << "Podaj wyjatek:\n"
					<< "1 - bad_alloc\n"
					<< "2 - bad_cast\n"
					<< "3 - bad_typeid\n"
					<< "4 - out_of_range\n"
					<< "5 - range_error\n"
					<< "6 - ios_base_failure\n"
					<< "7 - my_class\n"
					<< "0 - the end\n"
		;
		int a;
		cin >>a;

		switch(a)
		{

			case 1:
				BadAlloc();
				break;

			case 2:
				BadCast();
				break; 

			case 3:
				BadTypeid();
				break; 

			case 4:
				OutOfRange();
				break; 

			case 5:
				RangeError();
				break;
			
			case 6:
				IosBaseFailure();
				break;

			case 7:
				throw MyException();
				break;
			default:
				return 0;

		}
	}
	catch(std::exception& e)
	{
		cout.clear();
		cout << "Przyczyna: " << e.what() << "\n";
		cout << "Klasa: " << typeid(e).name() << "\n";
	}
	}
}