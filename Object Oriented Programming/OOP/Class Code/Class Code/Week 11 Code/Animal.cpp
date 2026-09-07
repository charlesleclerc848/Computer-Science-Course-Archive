#include<iostream>
using namespace std;
class Animal{
	public:
		virtual void speak(){
			cout<<"Animal speak\n";
		}
};
class Dog: public Animal{
	public:
		void speak() override {
			cout<<"Dog barks\n";
		}
};

class Cat : public Animal{
	public:
		void speak(){
			cout<<"Cat meows\n";
		}
};

int main(){
	Animal *a;
	Dog d;
	Cat c;
	
	a = &d;
	a->speak();

	a = &c;
	a->speak();	
}










