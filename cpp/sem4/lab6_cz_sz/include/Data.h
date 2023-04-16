#ifndef _DATA_H_
#define _DATA_H_

#include <string>
#include <iostream>

/**
 * @brief Abstract base class for data
 * 
 */
class Data
{
    public:
        /**
         * @brief Virtual destructor to allow for polymorphism
         * 
         */
        virtual ~Data();
        /**
         * @brief Pure virtual function to print the data
         * 
         */
        virtual void print(std::ostream& strm) const = 0;
        /**
         * @brief Getter for _next
         * 
         *
         * @return pointer to the next data
         */
        Data* next() const;
        /**
         * @brief Setter for _next
         * 
         *
         * @param next
         */
        void SetNext(Data* next);
        
    protected:
        Data* _next = nullptr;
};

/**
 * @brief Class for integer data
 * 
 */
class IntData : public Data
{
    public:
        /**
         * @brief Constructor for IntData
         * 
         *
         * @param value
         */
        IntData(const int& value);
        /**
         * @brief Copy constructor for IntData
         * 
         *
         * @param other
         */
        IntData(const IntData& other);
        /**
         * @brief Destructor for IntData
         * 
         */
        virtual ~IntData() override = default;
        /**
         * @brief Copy assignment operator for IntData
         * 
         *
         * @param other
         * @return the copied IntData
         */
        IntData operator=(const IntData& other) const;
        /**
         * @brief Prints the value of the data
         * 
         */
        virtual void print(std::ostream& strm) const override;
        /**
         * @brief Overloaded operator* for IntData
         * 
         *
         * @return the value of the data
         */
        int value() const;
        
    private:
        int _value;
};

/**
 * @brief Class for string data
 * 
 */
class StringData : public Data
{
    public:
        /**
         * @brief Constructor for StringData
         * 
         *
         * @param value
         */
        StringData(const char* value);
        /**
         * @brief Constructor for StringData
         * 
         *
         * @param value
         */
        StringData(const std::string& value);
        /**
         * @brief Copy constructor for StringData
         * 
         *
         * @param other
         */
        StringData(const StringData& other);
        /**
         * @brief Destructor for StringData
         * 
         */
        virtual ~StringData() override = default;
        /**
         * @brief Copy assignment operator for StringData
         * 
         *
         * @param other
         * @return the copied StringData
         */
        StringData operator=(const StringData& other) const;
        /**
         * @brief Prints the value of the data
         * 
         */
        virtual void print(std::ostream& strm) const override;
        /**
         * @brief Overloaded operator* for StringData
         * 
         *
         * @return the value of the data
         */
        std::string value() const;
        
    private:
        std::string _value;
};

class Boolean : public Data
{
    public:
        /**
         * @brief Constructor for Boolean
         * 
         *
         * @param value
         */
        Boolean(const bool& value);
        /**
         * @brief Copy constructor for Boolean
         * 
         *
         * @param other
         */
        Boolean(const Boolean& other);
        /**
         * @brief Destructor for Boolean
         * 
         */
        virtual ~Boolean() override = default;
        /**
         * @brief Copy assignment operator for Boolean
         * 
         *
         * @param other
         * @return the copied Boolean
         */
        Boolean operator=(const Boolean& other) const;
        /**
         * @brief Prints the value of the data
         * 
         */
        virtual void print(std::ostream& strm) const override;
        /**
         * @brief Overloaded operator* for Boolean
         * 
         *
         * @return the value of the data
         */
        bool value() const;
        
    private:
        bool _value;
};

typedef Data LData;

std::ostream& operator<<(std::ostream& strm, const Data& data);

#endif