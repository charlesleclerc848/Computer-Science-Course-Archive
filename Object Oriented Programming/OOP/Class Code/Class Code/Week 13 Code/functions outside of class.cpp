#include<iostream>
using namespace std;
template <typename T>
class myClass{
	T commonVar;
	public:
		myClass(T cv);
		void display();
		T print();
};

template <typename T>
myClass<T>::myClass(T cv){
	commonVar = cv;
}

template <typename TT>
void myClass<TT>::display(){
	cout<<"Value of common variable is : "<<commonVar<<endl;
}
		
template <typename TT>
TT myClass<TT>::print(){
	return commonVar;
}

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