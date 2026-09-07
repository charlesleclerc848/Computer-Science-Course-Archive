#include<iostream>
using namespace std;

class Base{
	public:
	Base(){
		cout<<"Base constructor called\n";
	}
	
	virtual ~Base(){
		cout<<"Base destructor called\n";
	}
};

class Child:public Base{
	public:
	Child(){
		cout<<"Child constructor called\n";
	}
	
	~Child(){
		cout<<"Child destructor called\n";
	}
};

int main(){
	Base *b;
	Child c;
	
	b = &c;
	
	delete b;
}








