#include <iostream>
using namespace std;

void fibonacci(int& first, int& second, int& next) {
    next = first + second; 
    first = second;	
    second = next;  
}

int main()
{
    int count, first = 0, second = 1, next;
    cout << "Enter the number of terms: ";
    cin >> count;

    cout << "Fibonacci Series: ";
	cout << first << " " << second << " ";
	for(int i=2; i<count; i++)
	{
		fibonacci(first, second, next);
		cout << next << " ";	
	}
    return 0;
}

