#include<iostream>
using namespace std;

class Base{
	public:
	Base(){
		cout<<"Base Default Constructor\n";
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
	~Child(){
		cout<<"Child Default Destructor\n";
	}
};


int main()
{
	Child c1;
}





