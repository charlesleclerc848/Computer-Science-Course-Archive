#include<iostream>
using namespace std;

template <class T>
void compare(T a, T b){
	if(a>b){
		cout<<"Value a is greater : "<<a<<endl;
	}
	else
	{
		cout<<"Value b is greater : "<<b<<endl;
	}
}

int main(){
	compare(5,10);
	compare(5.5, 8.8);
	compare('A', 'B');
}