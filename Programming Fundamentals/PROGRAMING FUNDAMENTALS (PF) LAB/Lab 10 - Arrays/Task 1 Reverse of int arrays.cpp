#include<iostream>
using namespace std;
int main() {
	int n, c, d = 0, a[100], b[100];
	cout<<"Enter the number of elements in array : ";
	cin>>n;
	cout<<"Enter " <<n<< " integer(s) : ";
	
	for (c = 0; c < n; c++) 
	{
		cin>>a[c];
	}
	
	for (c = n - 1; c >= 0; c--)
	{
		b[d] = a[c];
		d++;
	}
	
	for (c = 0; c < n; c++) 
	{
		a[c] = b[c];
	}		
	
	cout<<"Reverse array is : ";
	for (c = 0; c < n; c++) 
	{
		cout<<a[c]<<" ";
	}	
	return 0;
}
