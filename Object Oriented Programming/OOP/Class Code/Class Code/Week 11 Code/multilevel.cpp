#include<iostream>
using namespace std;

class A{
	public:
		virtual void show(){
			cout<<"Class A show() called\n";
		}
};

class B: public A{
	public:
//		void show(){
//			cout<<"Class B show() called\n";
//		}

		void show() override;
};

void B::show(){
	cout<<"Class B show() called\n";
}

class C: public B{
	public:
		void show(){
			cout<<"Class C show() called\n";
		}
};

int main(){
	A *aPtr;
	B b;
	C c;
	
	aPtr = &c;
	aPtr->show();
}










