#include <iostream>
using namespace std;

int main() {
    int number = 12;
    int count = 0;

    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            count++;
        }
    }

    cout << "Number of factors using for loop : " << count << endl;

	// By using while loop
	
	int j=1, counter=0;
	while (j<=number)
	{
		if(number % j == 0)
		{
			counter++;
		}
		j++;
	}

	cout << "Number of factors using while loop : " << count << endl;

    return 0;
}

