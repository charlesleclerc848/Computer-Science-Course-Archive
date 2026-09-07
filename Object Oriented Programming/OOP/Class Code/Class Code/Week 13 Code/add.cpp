#include<iostream>
using namespace std;

template <typename T>
void add(T a, T b){
	cout<<"Addition is : "<<a+b<<endl;
}

//void add(double a, double b){
//	cout<<"Addition is : "<<a+b<<endl;
//}

int main(){
	add(5,10);
	add(5.5, 8.8);
}