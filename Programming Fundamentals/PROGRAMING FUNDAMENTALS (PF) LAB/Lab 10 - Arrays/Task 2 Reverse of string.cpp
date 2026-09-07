#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char arr[]) {
    int length = strlen(arr);
    int start = 0;
    int end = length - 1;

    for(start=0; start<end; start++) {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        end--;
    }
}

int main() {
    char arr[100];

    cout << "Enter a string: ";
    cin.getline(arr, 100);

    reverseString(arr);

    cout << "Reversed String: " <<arr;

    return 0;
}

