#include <iostream>
using namespace std;
int main()
{
	int a,prime;
	cout<<"Enter the number : ";
	cin>>a;
	//for prime number we know that it is divisible by itself and the 1 so that
	for(int i=2;i<a;i++)
	{
		prime=a%i;
		if(a%i==0)
		{
			cout<<a<<" is not prime number";
			break;	
		}	
	}
		 if(prime==1)
		{
			cout<<a<<" is prime number";
		}
	
	
	return 0;
}
