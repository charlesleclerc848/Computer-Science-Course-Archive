#include<iostream>
using namespace std;
long factorial(int);
int main()
{
	int number;
	cout<<"Enter a number: ";
	cin>>number;
	cout<<"Factorial of "<<number<<" is = "<<factorial(number);
	return 0;
}
long factorial(int x)
{
	long temp = 1;	
	for(int i = x; i>0; i--)
		temp = temp*i;
	return temp;
}
