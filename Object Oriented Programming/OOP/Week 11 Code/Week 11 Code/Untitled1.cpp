#include<iostream>
using namespace std;
class base_class{
	public:
	int var1;
	virtual void display(){
		cout<<"Base Class "<<endl;
	}	
};

class derived_class : public base_class{
	public:
	int var2;
	void display(){
		cout<<"Derived Class "<<endl;
	}	
};

int main(){
base_class *ptr_base;
base_class 	obj_base;
ptr_base = &obj_base;
ptr_base->display();
derived_class 	obj_der;
ptr_base = &obj_der;
ptr_base->display();	
	
	
	
}




