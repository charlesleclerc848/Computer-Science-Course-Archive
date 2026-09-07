#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    char c;
    
    // Example of getline function
    cout << "Enter a string using getline function: ";
    getline(cin, str2);
    cout << "You entered: " << str2 << endl <<endl;
    
    // Example of a string
    cout << "Enter a string : ";
    cin>>str1;
    cout << "You entered: " << str1 << endl <<endl;
    
    // Example of a char
    cout << "Enter a character using cin: ";
    cin >> c;
    cout << "You entered: " << c << endl;
    
    return 0;
}

