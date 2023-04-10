#pragma once
#include "Data.h"

class List
{
	private:
		Data * _data;
		List * _next;
	public:
		enum side {Begin, End};
		List() : _data(nullptr), _next(nullptr) {}
		List(Data && data, List * _next = nullptr) : _data(std::move(&data)), _next(_next) {}
		List & insert(Data &obj, side where = End)
		{
			//if empty
			if(_data == nullptr)
				_data = &obj;
			else
			{
				if(where == End)
				{
					List *temp = this;
					while(temp->_next != nullptr)
						temp = temp->_next;
					temp->_next = new List(std::move(obj));
				}
				else
				{
					List *temp = new List(std::move(*_data),_next);
					_data = &obj;
					_next = temp;

				}
				else
				{
					List *temp = new List(std::move(*(this->_data)),this->_next);
					this->_data = _data;
					this->_next = temp;
				}
				
			}
			return *this;
		}
		void print() 
		{
			List *temp = this;
			while(temp != nullptr)
			{
				std::cout << ", " ;
				this->_data->printData();
				temp = temp->_next;
			}	
		}

};