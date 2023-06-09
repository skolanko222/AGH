#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "/usr/include/gsl/gsl_math.h"
#include "/usr/include/gsl/gsl_linalg.h"

#define max(X,Y) ((X)>(Y)? (X):(Y))
#define min(X,Y) ((X)<(Y)? (X):(Y))
#define abs(X) ((X)>0? (X):-(X))

namespace my_gsl
{
	class matrix
	{
		private:
			gsl_matrix *_m;
			size_t _x;
			size_t _y;
		public:
			//default constructor
			matrix(size_t x = 1, size_t y = 1) : _m(gsl_matrix_calloc(x,y)), _x(x), _y(y)
			{
				std::cout << __PRETTY_FUNCTION__ << std::endl;
			}
			matrix(const char * file_name,const size_t x,const size_t y) : matrix(x,y)
			{
				std::cout << __PRETTY_FUNCTION__ << std::endl;
				FILE * file_ptr = fopen(file_name, "r");
				if(gsl_matrix_fscanf(file_ptr, _m))
					std::cout << "Problem z odczytem pliku: " << file_name << std::endl;
				fclose(file_ptr);
			}
			matrix & operator=(const matrix & copy_m) 
			{
				std::cout << __PRETTY_FUNCTION__ << std::endl;
				if(this == & copy_m)
				 	return *this;
				_x = copy_m._x;
				_y = copy_m._y;				
				gsl_matrix_free(_m);
				_m = gsl_matrix_calloc(_x, _y);
				gsl_matrix_memcpy(_m, copy_m._m);
				return *this;
			}

			matrix(const matrix & copy_m) : matrix(copy_m._x, copy_m._y)
			{
				std::cout << __PRETTY_FUNCTION__ << std::endl;
				gsl_matrix_memcpy(_m, copy_m._m);

			}

			matrix & operator+(const matrix & right_m)
			{
				if( _x == right_m._x && _y == right_m._y)
				{
					std:: cout << "Wymiary musza byc takie same!\n";
				}
				for(size_t i = 0; i < _x; i++)
					for(size_t j = 0; j < _x; j++)
						gsl_matrix_set(_m,i,j,gsl_matrix_get(_m,i,j) + gsl_matrix_get(right_m._m,i,j));
				return *this;
			}
			void print()
			{
				for(size_t i = 0; i < _x; i++)
				{
					for(size_t j = 0; j < _x; j++)
						std::cout << gsl_matrix_get(_m,i,j) << ' ';
					std::cout << std::endl;
				}
			}
			~matrix()
			{
				std::cout << __PRETTY_FUNCTION__ << std::endl;
				if(_m != nullptr)
					gsl_matrix_free(_m);
				_m = nullptr;
				_x = 0;
				_y = 0;
			}


	};

	// matrix & operator*(const matrix & right_m)
	// {
	// 	for(size_t i = 0; i < right_m._x; i++)
	// 		for(size_t j = 0; j < right_m._x; j++)
	// 			gsl_matrix_set(_m,i,j, (*this) * gsl_matrix_get(right_m._m,i,j));
				
	// 	return *this;

	// }	


}