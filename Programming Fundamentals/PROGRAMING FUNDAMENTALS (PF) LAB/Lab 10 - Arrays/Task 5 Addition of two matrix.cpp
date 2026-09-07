#include <iostream>
using namespace std;
int main()
{
	int a[3][3],b[3][3],c[3][3];
	int row,col;
	cout<<"Enter nine elements of a 3X3 Matrix A : ";
	for(row=0; row<3; row++)
	{
		for(col=0; col<3; col++)
		{
			cin>>a[row][col];
		}	
	}
	cout<<"\nEnter nine elements of a 3X3 Matrix B : ";
	for(row=0; row<3; row++)
	{
		for(col=0; col<3; col++)
		{
			cin>>b[row][col];
		}
	}
	cout<<"\nSum of two matrix is\n";
	for(row=0 ; row<3 ; row++)
	{
		for(col=0 ; col<3 ; col++)
		{
			c[row][col]=a[row][col]+b[row][col];
			cout<<c[row][col]<<" ";
		}
	cout<<"\n";
	}
	return 0;
}
