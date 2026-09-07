#include <iostream>
#include <cstring>
using namespace std;
int main () 
{
	char arr[100];
	cout<<"Enter a string to reverse : ";
	cin.getline(arr,100);
	strrev(arr);
	cout<<"Reverse of entered string is : "<<arr<<endl;
	return 0;
}
