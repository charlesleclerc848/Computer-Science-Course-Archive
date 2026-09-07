#include <iostream>
using namespace std;
int main()
{
	int upper,lower,prime;
	cout<<"Enter the lower limit"<<endl;
	cin>>lower;
	cout<<"Enter the upper limit"<<endl;
	cin>>upper;
{
	for(int i=lower;i<=upper;i++)
	{
		for(int j=2;j<i;j++)
	{
			prime=i%j;
		if(prime==0)
		{
			cout<<i<<" is not prime."<<endl;
			break;
		}
	}
	 if(prime==1)
		{
			cout<<i<<" is a prime."<<endl;
			
		}
	}
}
	return 0;
}