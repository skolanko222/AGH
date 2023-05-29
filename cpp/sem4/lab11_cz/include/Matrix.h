#pragma once

#include <iostream>

template<typename T, int row, int col>
class Matrix
{
	private:
		T _arr[row][col];
	public:
		Matrix(T a = 0) {reset(a);}
		void reset(T val)
		{
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
					_arr[i][j] = val;
			}

		}
		// T at(int i, int j) const {return _arr[i][j];}

		T & at(int i, int j) {return _arr[i][j];}


		template<int i, int j>
		T & at() {return _arr[i][j];}

		template<typename T2>
		void add(Matrix<T2,row,col> b);

		friend std::ostream & operator<<(std::ostream& o, Matrix<T,row,col> m)
		{
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
					o << m.at(j,i) << " ";
				o << "\n";
			}
			return o;
		}
};

template<typename T, int row, int col>
template<typename T2>
void Matrix<T,row,col>::add(Matrix<T2,row,col> b) 
{
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
			_arr[i][j] += b.at(i,j);
	}

}