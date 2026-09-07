#include<iostream>
using namespace std;
int main() {
	int maximum, c, n;
	cout<<"Enter the number of elements in array: ";
	cin>>n;
	int array[n];
	cout<<"Enter " <<n<< " integer(s) : ";
	for (c = 0; c < n; c++)
		cin>>array[c];
	maximum = 0;
	for (c = 1; c < n; c++)
	{
		if (array[c] > array[maximum])
		{
			maximum = c;
		}
	}
	cout<<"Maximum element is present at index "<<maximum<<" and it's value is "<<array[maximum]<<endl;
	return 0;
}
