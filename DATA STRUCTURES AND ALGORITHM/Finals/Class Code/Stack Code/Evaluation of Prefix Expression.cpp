#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// Function to evaluate prefix expression
int evaluatePrefix(string prefix) {
    stack<int> s;
    int i = prefix.length() - 1; // Start from right

    while (i >= 0) {
        char c = prefix[i];

        // If operand, push to stack
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        }
        // If operator, pop two values and perform operation
        else {
            int val1 = s.top(); 
			s.pop();
            int val2 = s.top(); 
			s.pop();
            switch (c) {
                case '+': 
					s.push(val1 + val2); 
					break;
                case '-': 
					s.push(val1 - val2); 
					break;
                case '*': 
					s.push(val1 * val2); 
					break;
                case '/': 
					s.push(val1 / val2); 
					break;
                case '^': 
					s.push(pow(val1, val2)); 
					break;
            }
        }
        i--;
    }
    return s.top();
}

// Main function
int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;

    return 0;
}
