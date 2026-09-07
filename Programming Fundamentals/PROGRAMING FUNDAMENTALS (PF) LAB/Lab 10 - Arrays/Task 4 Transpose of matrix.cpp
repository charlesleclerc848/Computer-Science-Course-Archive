#include <iostream>
using namespace std;
int main()
{
	int a[3][3];
	int row,col;
	cout<<"Enter nrowne elements of a 3X3 Matrix : ";
	for(row=0; row<3; row++)
	{
		for(col=0; col<3; col++)
		{
			cin>>a[row][col];
		}
	}
	cout<<"\nOriginal 3X3 Matrix is : "<<endl;
	for(row=0 ; row<3 ; row++)
	{
		for(col=0 ; col<3 ; col++)
		{
			cout<<a[row][col]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\nTransposed 3X3 Matrix is : "<<endl;
	for(row=0 ; row<3 ; row++)
	{
		for(col=0 ; col<3 ; col++)
		{
			cout<<a[col][row]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
