#include <iostream>
using namespace std;
void swap_value(int, int);
int main()
{
	int one,two;
	cout<<"Enter first number: ";
	cin>>one;
	cout<<"Enter second number: ";
	cin>>two;
	cout<<"Before Swap first number is "<<one<<" and second number is "<<two<<endl;
	swap_value(one, two);
	return 0;
}
void swap_value(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
	cout<<"After Swap first number is "<<num1<<" and second number is "<<num2<<endl;
}
