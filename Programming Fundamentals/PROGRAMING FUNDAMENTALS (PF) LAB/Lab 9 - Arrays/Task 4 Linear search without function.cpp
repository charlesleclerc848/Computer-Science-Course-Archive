#include<iostream>
using namespace std;
int main() {
	int search, c, n;
	cout<<"Enter the number of elements in array: ";
	cin>>n;
	int array[n];
	cout<<"Enter " <<n<< " integer(s) : ";
	for (c = 0; c < n; c++)
		cin>>array[c];
	cout<<"Enter the number to search: ";
	cin>>search;
	for (c = 0; c < n; c++)
	{
		if (array[c] == search) // if required element found
		{
			cout<<search<<" is present at index: " <<c<<endl;
			break;
		}
	}
	if (c == n)
	cout<<search<<" is not present in array."<<endl;
	return 0;
}
