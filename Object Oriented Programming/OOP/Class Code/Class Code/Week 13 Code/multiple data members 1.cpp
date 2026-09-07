#include<iostream>
using namespace std;

template<class T1, class T2>
class myClass{
	T1 variable1;
	T2 variable2;
	public:
		myClass(){
		}
		myClass(T1 var1, T2 var2){
			variable1 = var1;
			variable2 = var2;
		}
		
		void display(){
			cout<<"Value of variable 1 is : "<<variable1<<endl;
			cout<<"Value of variable 2 is : "<<variable2<<endl;
		}
		
		void setValues(T1 var1, T2 var2){
			variable1 = var1;
			variable2 = var2;
		}
};

int main(){
	myClass<int, string> obj1(1001, "Ali Khan");
	myClass<double, string> obj2(13.42, "Umair CR");
	myClass<int, char> obj3;
	
	obj3.setValues(134, 'C');
	
	obj1.display();
	obj2.display();
	obj3.display();
}











