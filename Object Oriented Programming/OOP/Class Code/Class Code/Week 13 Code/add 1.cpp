#include<iostream>
using namespace std;

template <typename T>
void add(T a, T b){
	cout<<"Addition of two integers is : "<<a+b<<endl;
}

//void add(int a, int b){
//	cout<<"Addition of two int numbers is : "<<a+b<<endl;
//}
//void add(float a, float b){
//	cout<<"Addition of two flot numbers is : "<<a+b<<endl;
//}

int main(){
	add(5.4f,6.9f);
	add(2,3);
	add(3.1,6.3);
}