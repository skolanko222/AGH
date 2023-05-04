struct A {
  virtual void foo() const 
  {}
  void bar()
  {}
};

struct B : A {
  void foo() const override
  {}

  void foo() override; // Error: B::foo does not override A::foo const
  // void bar() override;       // Error: A::bar is not virtual
};

int main(int argc, char *argv[]) {
	A a;
	B b;
}
