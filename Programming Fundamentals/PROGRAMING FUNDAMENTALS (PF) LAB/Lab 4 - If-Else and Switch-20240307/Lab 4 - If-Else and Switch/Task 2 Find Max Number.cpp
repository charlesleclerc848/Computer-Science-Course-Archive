#include<iostream>
using namespace std;
int main()
{
	int num1,num2,num3,num4,num5;
	cout<<"Enter 1st number: ";
	cin>>num1;
	cout<<"Enter 2nd number: ";
	cin>>num2;
	cout<<"Enter 3rd number: ";
	cin>>num3;
	cout<<"Enter 4th number: ";
	cin>>num4;
	cout<<"Enter 5th number: ";
	cin>>num5;
	if(num1>num2 && num1>num3 && num1>num4 && num1>num5)
	cout<<num1<<" is the gretest"<<endl;
	else if(num2>num1 && num2>num3 && num2>num4 && num2>num5)
	cout<<num2<<" is the gretest"<<endl;
	else if(num3>num1 && num3>num2  && num3>num4 && num3>num5)
	cout<<num3<<" is the gretest"<<endl;
	else if(num4>num1 && num4>num2 && num4>num3 && num4>num5)
	cout<<num4<<" is the gretest"<<endl;
	else if(num5>num1 && num5>num2 && num5>num3 && num5>num4)
	cout<<num5<<" is the gretest"<<endl;
	return 0;
}
