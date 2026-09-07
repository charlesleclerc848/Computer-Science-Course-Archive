#include<iostream>
using namespace std;
int main()
{
	int input;
	cout<<"Enter a number:";
	cin>>input;
	if (input>0)
	{
		cout<<"Your entered number "<<input<<" is a positive number.";	
	}
	else
	{
		cout<<"Your entered number "<<input<<" is a negative number.";
	}
	return 0;
}
