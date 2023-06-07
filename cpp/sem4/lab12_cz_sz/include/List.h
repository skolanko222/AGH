#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"
#include "Pair.h"
#include <iostream>

/**
 * @brief Class storing methods, head and tail of one-way list
 * 
 */
class List
{
    public:
        /**
         * @brief Destroy the List object
         * 
         */
        ~List() { delete _head;}
        /**
         * @brief Method adding new node to start of the list
         * 
         * @tparam T 
         * @param data 
         */
        template <typename T>
        void add(const T& data)
        {
            auto tmp = new TNode<T>(data);
            if (_head == nullptr)
            {
                _head = tmp;
                _tail = tmp;
            }
            else
            {
                tmp->next(_head);
                _tail = _head;
                _head = tmp;
            }
        }
        /**
         * @brief Getter for head
         * 
         * @return Node* 
         */
        Node* head() const
        { 
            return _head; 
        } 
    private:
        Node* _head = nullptr;
        Node* _tail = nullptr;
};

#endif // _LIST_H_