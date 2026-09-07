#include<iostream>
using namespace std;

template <class T1, class T2>
class myClass{
	T1 variable1;
	T2 variable2;
	public:
		myClass(T1 var1, T2 var2){
			variable1 = var1;
			variable2 = var2;
		}
		
		void display(){
			cout<<"Value of variable 1 is : "<<variable1<<endl;
			cout<<"Value of variable 2 is : "<<variable2<<endl<<endl<<endl;
		}
};

int main(){
	myClass<int, string> obj1(1, "Ali Ahmad");
	myClass<int, char> obj2(2, 'E');
	myClass<double, string> obj3(100.3, "Rafay Rana");
	
	obj1.display();
	obj2.display();
	obj3.display();
}















