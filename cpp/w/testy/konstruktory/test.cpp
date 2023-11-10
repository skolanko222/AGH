class A
{
	private:
	 int x = 0;
};
class B : protected A
{
	public:
	int fun() {return x;}
};
class C : private B
{
	public:
	int fun() {return x;}
	
};

int main(void)
{
	C ca;
	return;
}