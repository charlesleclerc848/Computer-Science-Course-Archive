#include<iostream>
using namespace std;
class base{
	public:
	base(){
		cout<<"Base Class constructor"<<endl;
	}
    virtual ~base(){
		cout<<"Base Class destructor"<<endl;
	}	
	
};

class derived : public base{
	public:
	derived(){
		cout<<"Derive Class constructor"<<endl;
	}
    ~derived(){
		cout<<"Derive Class destructor"<<endl;
	}	
	
};

int main(){
	base *b;
	derived d;
	
	b=&d;
	delete b;
	
}