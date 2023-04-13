#pragma once
#include "Data.h"

class List
{
	private:
		Data * _data;
		List * _next;
	public:
		enum side {Begin, End};
		List(Data * d = nullptr, List * n = nullptr ) : _data(d), _next(n) {}
		List(List & obj);
		~List();
		List & insert(const IntData &obj, side where = End);
		List & insert(const StringData &obj, side where = End);
		List & insert(const Boolean &obj, side where = End);
		Data * clone_if_exists(const IntData &obj)
		{
			List * temp = this;
			int tr = obj.getData();
			while(temp != nullptr && !temp->_data->isEqual(tr) )
			{
				std::cout << temp->_data->toString() << '\n';
				temp = temp->_next;
			}
			if(temp == nullptr) return nullptr;
			IntData *ret = new IntData(static_cast<IntData *>(temp->_data)->getData());
			return ret;
			
		}
		Data * clone_if_exists(const StringData &obj)
		{
			List * temp = this;
			while(temp != nullptr && !temp->_data->isEqual(obj.getData()) ) temp = temp->_next;
			if(temp == nullptr) return nullptr;
			StringData *ret = new StringData(static_cast<StringData *>(temp->_data)->getData());
			return temp == nullptr ? nullptr : ret;
			 
		}
		List & numeric() {}
		List & non_numeric() {}
		void print();
		friend std::ostream& operator<<(std::ostream &o, const Data & obj);
};

std::ostream &operator<<(std::ostream &o, const Data & obj);