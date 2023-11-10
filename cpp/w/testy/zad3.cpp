#include <iostream>
template<typename T, int size = 2>
class CArray{
	T *arr;
	public:
		T & operator[](int i) const {return arr[i];}
		CArray() : arr(new T[size]) {};
		CArray(const CArray &o) : CArray() {
			for(int i = 0; i < size; i++)
				arr[i] = o.arr[i];
		}
		~CArray(){delete [] arr;}
};
template<typename T = int>
class box{
	T data;
	public:
		//box<T> & operator=(const box<T> &o) {data = o.data;return *this;}
		box<T> & operator=(const T &o) { data = o;return *this;}
		operator T() {return data;}
	friend std::ostream & operator<<(std::ostream& o, const box<T> & b)
	{
		return o << b.data;
	}
};

int main()
{
    using namespace std;
    CArray< box< >, 2 > a;
    double d = a[0] = a[1] = 1;

    const CArray< box< int > > b = a;
    b[0] = b[1] = 2;

    cout << "d = " << d << "\ta[0] = " << a[0] << "\ta[1] = "     << a[1] << endl;
    cout << "b[0] = " << b[0] << "\tb[1] = " << b[1];

    // return 0;
}

/*
d = 1    a[0] = 1    a[1] = 1
b[0] = 2    b[1] = 2
*/