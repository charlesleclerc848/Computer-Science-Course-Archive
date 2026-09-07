#include<iostream>
using namespace std;

template<typename T>
class myClass{
	T value;
	public:
		myClass(T val);
		
		void display();
};

template<typename B>
myClass<B>::myClass(B val){
	value = val;
}

template<typename C>
void myClass<C>::display(){
	cout<<"Value is : "<<value<<endl;
}

int main(){
	myClass<int> obj1(500);
	myClass<string> obj2("Hello World");
	myClass<char> obj3('A');
	
	obj1.display();
	obj2.display();
	obj3.display();
}