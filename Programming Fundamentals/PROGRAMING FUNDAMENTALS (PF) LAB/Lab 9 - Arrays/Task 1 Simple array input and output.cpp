#include<iostream>
using namespace std;
int main() {
	int n[5]; // n is an array of 5 integers
	for (int i = 0; i < 5; i++ )
	{
		cout<<"Please enter the element number "<<i+1<<": ";
		cin>>n[i];
	}
	cout<<endl;
	// output each array element's value
	for (int i = 0; i < 5; i++ )
		cout<<"Element stored at index "<<i<< " is: "<< n[i]<<endl;
	return 0;
}
