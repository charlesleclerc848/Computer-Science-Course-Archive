#include <iostream>
#include <stack>
#include<math.h>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    int i = 0;

    while (i < postfix.length()) {
        char c = postfix[i];

        // If operand, push to stack
        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        } 
        // If operator, pop two values and perform operation
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
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
        i++;
    }
    return s.top();
}

// Main function
int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
