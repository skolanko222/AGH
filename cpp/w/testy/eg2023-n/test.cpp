
template<typename T = float>
class A
{
	public:
	int a;
	A(int x) {}
	A(T x) {}
};

int main()
{
	A<>(2);

	return 0;
}