#include<iostream>
using namespace std;
int main()
{
	int num1, num2, num3;
	cout<<"Enter First Number : ";
    cin>>num1;
    
    cout<<"Enter Second Number : ";
    cin>>num2;

    num3=num1+num2;
    cout<<"\n Addition = "<<num3;

    num3=num1-num2;
    cout<<"\n Subtraction = "<<num3;

    num3=num1*num2;
    cout<<"\n Multiplication = "<<num3;

    num3=num1/num2;
    cout<<"\n Division = "<<num3;

    return 0;
}
