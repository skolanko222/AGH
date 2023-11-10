#include <iostream>
#include <array>

template<typename T=int>
struct box{
	box & operator=(T val){
			_val=val;
		
		return *this;
	}
	operator double()const{
		return static_cast<double>(_val);
	}

	private:
	T _val;
};

template<typename T, size_t size=2>
struct CArray{
	public:
	CArray(){
		for(unsigned i=0;i<size;i++){
			arr[i]=T{};
		}
	}
	T & operator[](size_t index)const{
		return arr[index];
	}

	private:
	mutable std::array<T,size> arr;
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

	return 0;
}

/*
d = 1    a[0] = 1    a[1] = 1
b[0] = 2    b[1] = 2
*/