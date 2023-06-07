#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class TNode;

/**
 * @brief basic node class for one-way list
 * 
 */
class Node
{
    public:
        /**
         * @brief Destroy the Node object
         * 
         */
        virtual ~Node() 
        { 
            delete _next; 
        }
        /**
         * @brief templated method returning true if type of this and passed template argument are the same/
         * 
         * @tparam T 
         * @return true 
         * @return false 
         */
        template <typename T>
        bool isType() const 
        {
            return dynamic_cast<const TNode<T>*>(this) != nullptr;
        }
        /**
         * @brief Setter for next
         * 
         * @param next 
         */
        void next(Node* next) 
        { 
            _next = next; 
        }
        /**
         * @brief Getter for next
         * 
         * @return Node* 
         */
        Node* next() const
        { 
            return _next;
        }
    private:
        Node* _next = nullptr;
};

/**
 * @brief Derived class from Node class. Templated class containing type T data
 * 
 * @tparam T 
 */
template <typename T>
class TNode final: public Node
{
    public:
        /**
         * @brief Construct a new TNode object
         * 
         * @param data 
         */
        TNode(const T& data) : _data(data) 
        {
        }
        /**
         * @brief Getter for data
         * 
         * @return T 
         */
        T get() const
        {
            return _data;
        }
    private:
        T _data;
};

#endif // _NODE_H_