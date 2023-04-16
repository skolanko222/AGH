#ifndef _LIST_H_
#define _LIST_H_

#include "Data.h"

class List
{
    public:
        /**
         * @brief Iterator for insert
         * 
         */
        enum Iter { Begin, End };

        /**
         * @brief Default constructor
         * 
         */
        List() = default;
        /**
         * @brief Copy constructor
         * 
         *
         * @param other
         */
        List(const List& other);
        ~List();
        /**
         * @brief copy assignment operator
         * 
         *
         * @param other 
         * @return 
         */
        List& operator=(const List& other);
        /**
         * @brief Inserts data into the list
         * 
         *
         * @param new_data
         * @param where
         * @return the list
         */
        List& insert(const Data& new_data, Iter where = End);
        /**
         * @brief Prints the list
         * 
         */
        void print() const;
        /**
         * @brief Reverses the list
         * 
         */
        void reverse();
        /**
         * @brief Return clone of data if it exists in the list or nullptr
         * 
         */
        LData* clone_if_exists(const Data& data) const;
        List numeric() const;
        List non_numeric() const;
    private:
        Data* _Begin = nullptr;
        Data* _End = nullptr;
};

#endif