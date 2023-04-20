#include "List.h"
List::List(List &obj) : List()
{
	List *old_list = &obj;
	while (old_list != nullptr)
	{
		old_list->_data->addToList(this);
		old_list = old_list->_next;
	}
}

List::~List()
{
	if(_next != nullptr)
		delete _next;
	delete _data;
}
List &List::insert(const StringData &obj, side where)
{
	StringData *data = new StringData(obj.getData());
	if (_data == nullptr)
	{
		_data = data;
		_next = nullptr;
		return *this;
	}
	else
	{
		if (where == End)
		{
			List *temp = this;
			while (temp->_next != nullptr)
				temp = temp->_next;
			temp->_next = new List(data, nullptr);
		}
		else if (where == Begin)
		{
			List *old_head = new List(_data, _next);
			_data = data;
			_next = old_head;
		}
	}
	return *this;
}
List &List::insert(const IntData &obj, side where)
{
	Data *data = new IntData(obj.getData());
	if (_data == nullptr)
	{
		_data = data;
		_next = nullptr;
		return *this;
	}
	else
	{
		if (where == End)
		{
			List *temp = this;
			while (temp->_next != nullptr)
				temp = temp->_next;
			temp->_next = new List(data, nullptr);
		}
		else if (where == Begin)
		{
			List *old_head = new List(_data, _next);
			_data = data;
			_next = old_head;
		}
	}
	return *this;
}
List &List::insert(const FloatData &obj, side where)
{
	Data *data = new FloatData(obj.getData());
	if (_data == nullptr)
	{
		_data = data;
		_next = nullptr;
		return *this;
	}
	else
	{
		if (where == End)
		{
			List *temp = this;
			while (temp->_next != nullptr)
				temp = temp->_next;
			temp->_next = new List(data, nullptr);
		}
		else if (where == Begin)
		{
			List *old_head = new List(_data, _next);
			_data = data;
			_next = old_head;
		}
	}
	return *this;
}

void List::print()
{
	List *temp = this;
	std::cout << '[';
	while (temp != nullptr)
	{
		temp->_data->printData();
		if (temp->_next != nullptr)
			std::cout << ", ";
		temp = temp->_next;
	}
	std::cout << "]\n";
}
bool List::find(const Data &obj) 
		{
			List * temp = this;
			while(temp != nullptr)
			{
				if(typeid(*(temp->_data)) == typeid(IntData))
				{
					if(dynamic_cast<const IntData *>(temp->_data)->isSame(obj))
						return true;
				}
				temp = temp->_next;
			}
			return false;
		}
List & List::operator<<(List & a) 
		{
			if(this == &a)
				return a;
			List * temp = &a;
			while(temp != nullptr)
			{
				temp->_data->addToList(this);
				temp = temp->_next;
				//temp->setPData(nullptr);
			}
			return a;
		}