#include<iostream>
using namespace std;

int main()
{
	int arr[4][4] = {{1,3,4,2},{6,9,8,7},{2,4,6,8},{7,1,3,4}};
	
	int row, col, matrixSum=0, diagonalSum1=0, diagonalSum2=0, boundrySum=0, rowMin, rowMax, colMin, colMax, matrixMin, matrixMax;
	
	cout<<"******** Original matrix ********\n\n";
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			cout<<arr[row][col]<<"\t";
		}
		cout<<endl;
	}
	
	cout<<"\n******** Sum of each row is given below ********\n\n";
	for(row=0; row<4; row++)
	{
		int rowSum = 0;
		for(col=0; col<4; col++)
		{
			rowSum = rowSum + arr[row][col];
		}
		cout<<"Sum of row "<<row+1<<" is = "<<rowSum<<endl;
	}
	
	cout<<"\n******** Sum of each column is given below ********\n\n";
	for(col=0; col<4; col++)
	{
		int colSum = 0;
		for(row=0; row<4; row++)
		{
			colSum = colSum + arr[row][col];
		}
		cout<<"Sum of column "<<col+1<<" is = "<<colSum<<endl;
	}
	
	cout<<"\nSum of matrix is = ";
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			matrixSum = matrixSum + arr[row][col];
		}
	}
	cout<<matrixSum<<endl;
	
	cout<<"\nSum of first diagonal is = ";
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			if(row==col)
			{
				diagonalSum1 = diagonalSum1 + arr[row][col];
			}
		}
	}
	cout<<diagonalSum1<<endl;
	
	cout<<"\nSum of second diagonal is = ";
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			if(row+col==3)
			{
				diagonalSum2 = diagonalSum2 + arr[row][col];
			}
		}
	}
	cout<<diagonalSum2<<endl;
	
	cout<<"\nSum of matrix boundry is = ";
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			if(row==0 || row==3 || col==0 || col==3)
			{
				boundrySum = boundrySum + arr[row][col];
			}
		}
	}
	cout<<boundrySum<<endl;
	
	cout<<"\n******** Maximum element in each row ********\n\n";
	for(row=0; row<4; row++)
	{
		rowMax = arr[row][0];
		for(col=0; col<4; col++)
		{
			if(rowMax < arr[row][col])
			{
				rowMax = arr[row][col];
			}
		}
		cout<<"The maximum element in row "<<row+1<<" is = "<<rowMax<<endl;
	}
	
	cout<<"\n******** Minimum element in each row ********\n\n";
	for(row=0; row<4; row++)
	{
		rowMin = arr[row][0];
		for(col=0; col<4; col++)
		{
			if(rowMin > arr[row][col])
			{
				rowMin = arr[row][col];
			}
		}
		cout<<"The minimum element in row "<<row+1<<" is = "<<rowMin<<endl;
	}
	
	cout<<"\n******** Maximum element in each column ********\n\n";
	for(col=0; col<4; col++)
	{
		colMax = arr[0][col];
		for(row=0; row<4; row++)
		{
			if(colMax < arr[row][col])
			{
				colMax = arr[row][col];
			}
		}
		cout<<"The maximum element in column "<<col+1<<" is = "<<colMax<<endl;
	}
	
	cout<<"\n******** Minimum element in each column ********\n\n";
	for(col=0; col<4; col++)
	{
		colMin = arr[0][col];
		for(row=0; row<4; row++)
		{
			if(colMin > arr[row][col])
			{
				colMin = arr[row][col];
			}
		}
		cout<<"The minimum element in column "<<col+1<<" is = "<<colMin<<endl;
	}
	
	cout<<"\nMaximum element in matrix is = ";
	matrixMax = arr[0][0];
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			if(matrixMax < arr[row][col])
			{
				matrixMax = arr[row][col];
			}
		}
	}
	cout<<matrixMax<<endl;
	
	cout<<"\nMinimum element in matrix is = ";
	matrixMin = arr[0][0];
	for(row=0; row<4; row++)
	{
		for(col=0; col<4; col++)
		{
			if(matrixMin > arr[row][col])
			{
				matrixMin = arr[row][col];
			}
		}
	}
	cout<<matrixMin<<endl;
}
