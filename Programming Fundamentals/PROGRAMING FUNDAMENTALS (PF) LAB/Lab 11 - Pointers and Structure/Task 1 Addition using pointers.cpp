#include <iostream>
using namespace std;
int main(){
	int first, second, *p, *q, sum;
	cout<<"Enter first number:";
	cin>>first;
	cout<<"Enter second number:";
	cin>>second;
	p = &first;
	q = &second;
	sum = *p + *q;
	cout<<"Address of first number : "<<p<<endl;
	cout<<"Address of second number : "<<q<<endl;
	cout<<"Sum of entered numbers: "<<sum<<endl;
	return 0;
}
