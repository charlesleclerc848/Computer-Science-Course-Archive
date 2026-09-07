#include <iostream>
using namespace std;
int main()
{
	for (int count = -5; count <= 0; count++)
	{
		
		// To execute break statement uncomment the below code
//		if(count==-2)
//		{
//			cout << "Countdown Stopped!\n";
//			break;
//		}

		// To execute continue statement uncomment the below code
		if(count==-2)
	{
			continue;
		}
		cout << count << ", ";
		
	}
	cout << endl;
	return 0;
}
