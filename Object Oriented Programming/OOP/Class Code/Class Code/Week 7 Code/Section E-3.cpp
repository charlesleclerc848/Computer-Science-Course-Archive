#include<iostream>
using namespace std;

class Base{
	public:
	Base(){
		cout<<"Base Default Constructor\n";
	}
	Base(int x, int y)
	{
		cout<<"Value of x in base class "<<x<<" y in base class "<<y<<endl;
	}
	~Base(){
		cout<<"Base Default Destructor\n";
	}
};

class Child : private Base{
	public:
	Child()
	{
		cout<<"Child Default Constructor\n";
	}
	Child(int a, int b) : Base(a,b)
	{
		cout<<"Child Parameterized Constructor\n";
	}
	~Child(){
		cout<<"Child Default Destructor\n";
	}
};


int main()
{
	Child c1(5,10);
}





