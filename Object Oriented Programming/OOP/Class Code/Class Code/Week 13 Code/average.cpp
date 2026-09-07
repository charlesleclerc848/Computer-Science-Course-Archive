#include<iostream>
using namespace std;

template <class E>
void average(E arr[], int size){
	E sum = 0;
	for(int i=0; i<size; i++){
		sum = sum + arr[i];
	}
	cout<<"Average of numbers is : "<<sum/size<<endl;
}

int main(){
	int arrayInteger[] = {1,2,3,4,5};
	double arrayDouble[] = {1.1,2.2,3.3,4.4,5.5};
	
	average(arrayInteger, 5); 
	average(arrayDouble, 5);
}