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
	if (this->_data != nullptr)
		delete this->_data;
	if (this->_next != nullptr)
		delete this->_next;
}
List &List::insert(StringData obj, side where)
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
List &List::insert(IntData obj, side where)
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