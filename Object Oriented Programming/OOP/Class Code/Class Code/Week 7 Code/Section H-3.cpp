#include<iostream>
using namespace std;

class Base{
	public:
		Base(){
			cout<<"Base default constructor\n";
		}
		Base(int x){
			cout<<"Value of x from base class = "<<x<<endl;
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
		Child(int a, int b):Base(b)
		{
			cout<<"Value of a from child class = "<<a<<endl;
		}
		~Child(){
			cout<<"Child destructor\n";
		}
};

int main(){
	Child c(3,5);
}







