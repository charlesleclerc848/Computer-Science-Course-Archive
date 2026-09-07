#include<iostream>
using namespace std;
class animal{
	public:
		void eat()
		{
			cout<<"Eating\n";
		}
};

class dog: public animal{
	public:
		void bark(){
			cout<<"Barking\n";
		}
};

int main()
{
	dog d;
	d.eat();
	d.bark();
}
