#include <iostream>
using namespace std;

int countVowels(char* str) 
{
    int count = 0;
    while (*str != '\0') 
	{
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' ||
            *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') 
		{
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[100];
    char * ptr = str;
    cout << "Enter a string: ";
    cin.getline(str, 100);
    int vowelCount = countVowels(ptr);
    cout << "Number of vowels in the string: " << vowelCount << endl;
    return 0;
}

