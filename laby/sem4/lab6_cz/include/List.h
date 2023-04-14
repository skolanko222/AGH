#pragma once
#include "Data.h"

class List
{
	private:
		Data * _data;
		List * _next;
		void dataPSet(Data * d) {_data = d;}
	public:
		enum side {Begin, End};
		List(Data * d = nullptr, List * n = nullptr ) : _data(d), _next(n) {}
		List(List & obj);
		List(List && obj);
		~List();
		List & insert(const IntData &obj, side where = End);
		List & insert(const StringData &obj, side where = End);
		List & insert(const Boolean &obj, side where = End);
		Data * clone_if_exists(const IntData &obj)
		{
			List * temp = this;
			int tr = obj.getData();

			while(temp != nullptr)
			{ 
				if (( typeid(*(temp->_data)) == typeid(IntData) ) && (temp->_data->isEqual(tr))) 
				{
						//std::cout << temp->_data->toString() << '\n';
						return new IntData(static_cast<IntData *>(temp->_data)->getData());
				}
				temp = temp->_next;
			}
			return nullptr;
			
		}
		Data * clone_if_exists(const StringData &obj)
		{
			List * temp = this;

			while(temp != nullptr)
			{ 
				if (( typeid(*(temp->_data)) == typeid(StringData) ) && (temp->_data->isEqual(obj.getData()))) 
				{
						//std::cout << temp->_data->toString() << '\n';
						return new StringData(static_cast<StringData *>(temp->_data)->getData());
				}
				temp = temp->_next;
			}
			return nullptr;
			
		}
		List numeric()
		{
			List * temp = this;
			List numeric_list;
			while(temp != nullptr)
			{ 
				if (( typeid(*(temp->_data)) == typeid(IntData) )) 
				{
					temp->_data->addToList(&numeric_list);
				}
				temp = temp->_next;
			}
			return numeric_list;
		}
		List non_numeric()
		{
			List * temp = this;
			List numeric_list;
			while(temp != nullptr)
			{ 
				if (( typeid(*(temp->_data)) == typeid(StringData) )) 
				{
					temp->_data->addToList(&numeric_list);
				}
				if (( typeid(*(temp->_data)) == typeid(Boolean) )) 
				{
					temp->_data->addToList(&numeric_list);
				}
				temp = temp->_next;
			}
			return numeric_list;
		}
		void print();
		friend std::ostream& operator<<(std::ostream &o, const Data & obj);
};

std::ostream &operator<<(std::ostream &o, const Data & obj);