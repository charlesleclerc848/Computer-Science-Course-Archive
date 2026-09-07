#include<iostream>
using namespace std;
int main() {
	int n[5];
	int i, sum = 0;
	for (i = 0; i < 5; i++ )
	{
		cout<<"Please enter the element number "<<i+1<<": ";
		cin>>n[i];
	}
	cout<<endl;
	for (i = 0; i < 5; i++ )
		sum = sum + n[i];
	cout<<"Sum of array elements is "<<sum<<endl;
	return 0;
}
