#include "Data.h"

Data::~Data()
{
    delete _next;
}

Data* Data::next() const
{
    return _next;
}

void Data::SetNext(Data* next)
{
    _next = next;
}

IntData::IntData(const int& value) : _value(value)
{
}

IntData::IntData(const IntData& other) : _value(other._value)
{
}

void IntData::print(std::ostream& strm) const
{
    strm << _value;
}

IntData IntData::operator=(const IntData& other) const
{
    return IntData(other);
}

int IntData::value() const
{
    return _value;
}

StringData::StringData(const char* value) : _value(value)
{
}

StringData::StringData(const std::string& value) : _value(value)
{
}

StringData::StringData(const StringData& other) : _value(other._value)
{
}

void StringData::print(std::ostream& strm) const
{
    strm << "\"" << _value << "\"";
}

StringData StringData::operator=(const StringData& other) const
{
    return StringData(other);
}

std::string StringData::value() const
{
    return _value;
}

Boolean::Boolean(const bool& value) : _value(value)
{
}

Boolean::Boolean(const Boolean& other) : _value(other._value)
{
}

void Boolean::print(std::ostream& strm) const
{
    strm <<  (_value ? "true" : "false");
}

Boolean Boolean::operator=(const Boolean& other) const
{
    return Boolean(other);
}

bool Boolean::value() const
{
    return _value;
}

std::ostream& operator<<(std::ostream& strm, const Data& data)
{
    data.print(strm);
    return strm;
}