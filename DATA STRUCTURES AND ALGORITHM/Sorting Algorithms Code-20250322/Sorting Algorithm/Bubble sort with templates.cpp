#include <iostream>
#include <string>
using namespace std;

// Template function for bubble Sort
template <typename T>
void bubleSort(T arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j=0; j < n-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
            	T temp = arr[j+1];
            	arr[j+1] = arr[j];
				arr[j] = temp;
          	}
    	}
	}
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
	  int intArr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(intArr) / sizeof(intArr[0]);
    cout << "Before sorting (integers): ";
    printArray(intArr, n);
    bubleSort(intArr, n);
    cout << "After sorting (integers): ";
    printArray(intArr, n);
    return 0;
}
