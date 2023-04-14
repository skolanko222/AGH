#include "List.h"

List::List(const List& other)
{

    Data* current = other._Begin;
    Data* current_there = _Begin;
    while ( current != nullptr )
    {
        if ( typeid(*current) == typeid(IntData) )
        {
            insert(*current , List::End );
        }
        else if ( typeid(*current) == typeid(StringData) )
        {
            insert(*current , List::End );
        }
        else if ( typeid(*current) == typeid(Boolean) )
        {
            insert(*current, List::End );
        }
        else
        {
            std::cout << "Error: Unknown type\n";
            return;
        }
        current = current->next();
    }
}

List::~List()
{
    reverse();
    delete _Begin;
    _Begin = nullptr;
    _End = nullptr;
}

List& List::insert(const Data& new_data, Iter where)
{
    if (typeid(new_data) == typeid(IntData))
    {
        IntData* new_int_data = new IntData(dynamic_cast<const IntData& >(new_data));
        if ( _Begin == nullptr )
        {
            _Begin = new_int_data;
            _End = new_int_data;
        }
        else if ( where == List::Begin )
        {
            new_int_data->SetNext( _Begin );
            _Begin = new_int_data;
        }
        else if ( where == List::End )
        {
            _End->SetNext ( new_int_data );
            _End = _End->next();
        }
        return *this;
    }
    else if (typeid(new_data) == typeid(StringData))
    {
        StringData* new_string_data = new StringData(dynamic_cast<const StringData&>(new_data));
        if ( _Begin == nullptr )
        {
            _Begin = new_string_data;
            _End = new_string_data;
        }
        else if ( where == List::Begin )
        {
            new_string_data->SetNext( _Begin );
            _Begin = new_string_data;
        }
        else if ( where == List::End )
        {
            _End->SetNext ( new_string_data );
            _End = _End->next();
        }
        return *this;
    }
    else if ( typeid(new_data) == typeid(Boolean) )
    {
        Boolean* new_boolean = new Boolean(dynamic_cast<const Boolean&>(new_data));
        if ( _Begin == nullptr )
        {
            _Begin = new_boolean;
            _End = new_boolean;
        }
        else if ( where == List::Begin )
        {
            new_boolean->SetNext( _Begin );
            _Begin = new_boolean;
        }
        else if ( where == List::End )
        {
            _End->SetNext ( new_boolean );
            _End = _End->next();
        }
        return *this;
    }
    else
    {
        std::cout << "Error: Unknown data type.\n";
        return *this;
    }
}

List& List::operator=(const List& other)
{
    if ( this == &other )
    {
        return *this;
    }
    Data* current = other._Begin;
    while ( current != nullptr )
    {
        insert(*current, List::End);
        current = current->next();
    }
    return *this;
}

void List::print() const
{
    Data* current = _Begin;
    std::cout << "[";
    while ( current != nullptr )
    {
        current->print(std::cout);
        std::cout << ((current->next() != nullptr) ? ", " : "");
        current = current->next();
    }
    std::cout << "]" << std::endl;
}

void List::reverse() 
{
    Data* current = _Begin;
    Data* previous = nullptr;
    Data* next = nullptr;
    while ( current != nullptr )
    {
        next = current->next();
        current->SetNext(previous);
        previous = current;
        current = next;
    }
    _End = _Begin;
    _Begin = previous;
}

LData* List::clone_if_exists(const Data& data) const
{
    if ( typeid(data) == typeid(IntData) )
    {
        Data* current = _Begin;
        IntData temp_copy_of_data = dynamic_cast<const IntData&>(data);

        while ( current != nullptr )
        {
            if ( typeid(*current) == typeid(IntData) )
            {
                if ( temp_copy_of_data.value() == dynamic_cast<IntData*>(current)->value() )
                {
                    return new IntData( dynamic_cast<IntData*>(current)->value() );
                }
            }
            current = current->next();
        }
    }
    else if ( typeid(data) == typeid(StringData) )
    {
        Data* current = _Begin;
        StringData temp_copy_of_data = dynamic_cast<const StringData&>(data);

        while ( current != nullptr )
        {
            if ( typeid(*current) == typeid(StringData) )
            {
                if ( temp_copy_of_data.value() == dynamic_cast<StringData*>(current)->value() )
                {
                    return new StringData( dynamic_cast<StringData*>(current)->value() );
                }
            }
            current = current->next();
        }
    }
    else if ( typeid(data) == typeid(Boolean) )
    {
        Data* current = _Begin;
        Boolean temp_copy_of_data = dynamic_cast<const Boolean&>(data);

        while ( current != nullptr )
        {
            if ( typeid(*current) == typeid(Boolean) )
            {
                if ( temp_copy_of_data.value() == dynamic_cast<Boolean*>(current)->value() )
                {
                    return new Boolean( dynamic_cast<Boolean*>(current)->value() );
                }
            }
            current = current->next();
        }
    }
    return nullptr;
}

List List::numeric() const
{
    List result;
    Data* current = _Begin;
    while ( current != nullptr )
    {
        if ( typeid(*current) == typeid(IntData) )
        {
            result.insert( *current, List::End );
        }
        current = current->next();
    }
    return result;
}

List List::non_numeric() const
{
    List result;
    Data* current = _Begin;
    while ( current != nullptr )
    {
        if ( typeid(*current) != typeid(IntData) )
        {
            result.insert( *current, List::End );
        }
        current = current->next();
    }
    return result;
}