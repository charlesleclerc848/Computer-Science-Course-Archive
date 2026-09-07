#include <iostream>
using namespace std;
int main() 
{
	int n;
	do 
	{
		cout << "Enter number (0 to end): ";
		cin >> n;
		cout << "You entered: " << n << "\n";
	} while (n != 0);
	cout << "Thank you. \n";
	return 0;
}
