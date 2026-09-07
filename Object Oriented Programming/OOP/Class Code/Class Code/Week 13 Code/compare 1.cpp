#include<iostream>
using namespace std;

template <typename tempDT>
tempDT compare(tempDT a, tempDT b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	cout<<"Comparison result of float values is : "<<compare(5.4f,6.9f)<<endl;
	cout<<"Comparison result of int values is : "<<compare(2,3)<<endl;
	cout<<"Comparison result of double values is : "<<compare(3.1,6.3)<<endl;
	cout<<"Comparison result of char values is : "<<compare('A','B')<<endl;
}