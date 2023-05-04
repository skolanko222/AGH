struct Base {
  virtual void foo() const
  {}
};
  
struct A : Base {
  void foo() const final
  {}

  // void bar() final; // Error: bar is non-virtual
};

struct B final : A {
  // void foo() const override; //Error: A:foo is final
};

struct C //: B  // Error: B is final
{
  
};

int main(int argc, char *argv[]) {
	A a;
	B b;
  C c;
}
