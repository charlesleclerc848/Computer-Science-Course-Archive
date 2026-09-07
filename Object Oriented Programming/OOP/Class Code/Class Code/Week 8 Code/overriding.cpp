#include<iostream>
using namespace std;
class Parent{
	public:
		void display(){
			cout<<"Parent class\n";
		}
};

class Child:public Parent{
	public:
		void display(){
			cout<<"Child class\n";
		}
};

int main(){
	Parent c;
	c.display();
}
