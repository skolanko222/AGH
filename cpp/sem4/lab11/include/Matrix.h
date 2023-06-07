#pragma once

#include <iostream>

template<typename T, int row, int col>
class Matrix
{
	private:
		T _arr[col][row];
	public:
		// konstruktor defaultowy
		Matrix(T val = 0) 
		{
			reset(val);
		}
		// funkcja ustawiajaca val w calej macierzy
		void reset(T val)
		{
			for(int i = 0; i < col; i++)
			{
				for(int j = 0; j < row; j++)
				{
					_arr[i][j] = val;
				}
			}
		}
		// przeladowany operator << na ostream
		friend std::ostream & operator<<(std::ostream & o, Matrix<T,row,col> m)
		{
			for(int i = 0; i < col; i++)
			{
				for(int j = 0; j < row; j++)
				{
					o << m._arr[j][i] << " ";
				}
				o << std::endl;
			}
			return o;
		}
		// templatowa metoda dostepu do elementu zwracajaca referencje
		template<int i, int j>
		T & at() {return _arr[i][j];}

		// getter elementu macierzy o indeksie [i][j]	
		T at(int i, int j) {return _arr[i][j];}

		// metoda transponujaca macierz kwadratowa
		Matrix<T,row,row> get_transpose() const
		{
			Matrix<T,row,row> a;
			a.add(*this);
			for(int i = 0; i < col; i++)
			{
				for(int j = 0; j < col; j++)
				{
					if(i != j)
						a._arr[i][j] = _arr[j][i];
				}
			}

			return a;
		}

		// metoda szablonowa dodajaca dwie macierze
		template<typename T2>
		void add(Matrix<T2,row,col> m);

};

template<typename T, int row, int col>
template<typename T2>
void Matrix<T,row,col>::add(Matrix<T2,row,col> m)
{ 
	for(int i = 0; i < col; i++)
	{
		for(int j = 0; j < row; j++)
		{
			_arr[i][j] += m.at(i,j);
		}
	}
}