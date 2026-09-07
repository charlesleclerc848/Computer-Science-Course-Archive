#include<iostream>
using namespace std;
template <typename T>
class myClass{
	T commonVar;
	public:
		myClass(T cv){
			commonVar = cv;
		}
		void display(){
			cout<<"Value of common variable is : "<<commonVar<<endl;
		}
		
		T print(){
			return commonVar;
		}
};

int main(){
	myClass<int> obj1(666);
	myClass<string> obj2("Section E");
	myClass<char> obj3('E');
	
	obj1.display();
	obj2.display();
	obj3.display();
	
	cout<<"Value of common variable from print is : "<<obj1.print()<<endl;
	cout<<"Value of common variable from print is : "<<obj2.print()<<endl;
	cout<<"Value of common variable from print is : "<<obj3.print()<<endl;
}