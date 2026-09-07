#include<iostream>
using namespace std;

class Base{
	public:
		Base(){
			cout<<"Base default constructor\n";
		}
		~Base(){
			cout<<"Base destructor\n";
		}
};

class Child:protected Base{
	public:
		Child(){
			cout<<"Child default constructor\n";
		}
		~Child(){
			cout<<"Child destructor\n";
		}
};

int main(){
	Child c;
}
