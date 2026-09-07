#include <iostream>
using namespace std;
int main()
{
	int a[3][3];
	int row,col;
	cout<<"Enter nine elements in the array:";
	for(row=0 ; row<3 ; row++)
	{
		for(col=0 ; col<3 ; col++)
		{
			cin>>a[row][col];
		}	
	}
	for(row=0 ; row<3 ; row++)
	{
		for(col=0 ; col<3 ; col++)
		{
			cout<<a[row][col]<<" ";
		}	
		cout<<"\n";
	}
	return 0;
}
