#include <iostream>

class Data
{
	public:
		virtual void print() const = 0;
		virtual auto get() const = 0;
		


		virtual ~Data() {}
};

class IntData : public Data
{
	public:
		IntData(int x) : _x(x) {}
		void print() const override
		{
			std::cout << _x << std::endl;
		}
		auto get() const override
		{
			return _x;
		}
	private:
		int _x;
};

class FloatData : public Data
{
	public:
		FloatData(float x) : _x(x) {}
		void print() const override
		{
			std::cout << _x << std::endl;
		}
		auto get() const override
		{
			return _x;
		}
	private:
		float _x;
};

int main()
{


	return 0;
}