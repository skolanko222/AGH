#pragma once

#include <iostream>
#include <string>

class type
{
	private:
		std::string _key;
		double _val;

	public:
		friend class Assoc;
		/**
		 * @brief overoading = operator with double argument
		 * 
		 * @param val 
		 * @return type& 
		 */
		type &operator=(double val)
		{
			_val = val;
			return (*this);
		}
		
		friend std::ostream &operator<<(std::ostream &o, const type &K);

};

class Assoc
{
	private:
		type *_arr;
		int _size;

	public:
		/**
		 * @brief Construct a new Assoc object
		 * 
		 */
		Assoc() : _arr(nullptr), _size(0) {} 
		/**
		 * @brief Destroy the Assoc object
		 * 
		 */
		~Assoc(){ delete [] _arr;}
		/**
		 * @brief Inserting and creating new Type obect of given arguments
		 * 
		 * @param name 
		 * @param val 
		 */
		void insert(std::string name, double val);
		/**
		 * @brief Prints whole assoc tabel
		 * 
		 * @param n 
		 */
		void print(std::string n) const;
		/**
		 * @brief overloaded [] operator returning Type object
		 * 
		 * @param name 
		 * @return type& 
		 */
		type &operator[](std::string name) const;
		/**
		 * @brief overloaded = operator returning Assoc object
		 * 
		 * @param val 
		 * @return Assoc& 
		 */
		 Assoc &operator=(Assoc &val) ;
		/**
		 * @brief returning median of values of an assoc table
		 * 
		 * @return double 
		 */
		double median();
		/**
		 * @brief function checking if key is present in the assoc table
		 * 
		 * @param key 
		 * @return true 
		 * @return false 
		 */
		bool contains(std::string key) const;
		/**
		 * @brief Coppying construct a new Assoc object
		 * 
		 * @param cpy 
		 */
		Assoc(Assoc & cpy){*this = cpy;} 
		
};
/**
 * @brief function printing " Znaleziono" if the key is present in the assoc table
 * 
 * @param val 
 * @return std::string 
 */
std::string print(bool val);