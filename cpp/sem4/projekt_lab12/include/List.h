#include <iostream>
template<typename T>
class TNode;

class Node
{
	public:
		Node(Node * n = nullptr) : _next(n) {};
		virtual ~Node() {}
		template<typename T>
		bool isType() 
		{
			// std::cout << static_cast<TNode<T>*>(this)->getData();
			// return typeid(dynamic_cast<TNode<T>*>(this)->getData()) == typeid(T) ? true : false; 
			return dynamic_cast<const TNode<T>*>(this) != nullptr;
		}
		virtual Node * next() const = 0;
		Node * getNext() const {return _next;}
		friend std::ostream & operator<<(std::ostream & o, const Node & n) {return o;}
	private:
		Node * _next;

};

template<typename T>
class TNode : public Node
{
	private:
		T _data;
	public:
		T  getData() {return _data;}
		TNode<T>* next() const override {return dynamic_cast<TNode<T>*>( getNext()); }
		TNode(T data = 0, Node * n = nullptr) : Node(n), _data(data) {}
		T get() const {return _data;}

};

class List
{
	private:
		Node *_head;
	public:
		List(Node * h = nullptr) : _head(h) {}
		Node * head(){return _head;}
		template<typename T>
		void add(const T & data) 
		{
			if(_head == nullptr)
				_head = new TNode<T>(data);
			else
			{
				Node * tmp = _head;
				_head = new TNode<T>(data, tmp);
			}
		}
		template<typename T>
		static Node & get(Node * obj) {}

		static Node & get(Node * obj) {}
};