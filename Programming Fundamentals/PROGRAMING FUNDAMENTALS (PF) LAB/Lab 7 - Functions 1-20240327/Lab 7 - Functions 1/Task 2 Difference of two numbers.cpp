#include <iostream>
using namespace std;
void difference(int, int); // Function Prototype
int main()
{
	int one,two;
	cout<<"Enter first number: ";
	cin>>one;
	
	cout<<"Enter second number: ";
	cin>>two;
	difference(one,two); // Function Call
	return 0;
}
void difference(int num1, int num2) // Function Definition
{
	cout<<"Difference = "<<num1-num2;
}
