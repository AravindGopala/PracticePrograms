#include <iostream>

using namespace std;

class A{
public:
	void virtual f(){
		cout<<"I am A"<<endl;
	};
};

class B: virtual public A{
public:
	void virtual f(){
		cout<<"I am B"<<endl;
	}
};

class C :virtual public A{
public:
	void virtual f(){
		cout<<"I am C"<<endl;
	}
};

class D :public C, public B {
public:
	void f(){
		cout<<"I am D"<<endl;
	}
};

int main()
{
	A *a;
	a = new D();
	a->f();
	return 0;
}
