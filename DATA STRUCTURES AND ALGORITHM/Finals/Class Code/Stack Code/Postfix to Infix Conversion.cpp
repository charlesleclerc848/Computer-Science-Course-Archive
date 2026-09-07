#include <iostream>
#include <stack>
using namespace std;

// Function to convert postfix to infix
string postfixToInfix(string postfix) {
    stack<string> s;
    int i = 0;

    while (i < postfix.length()) {
        char c = postfix[i];

        // If operand, push to stack
        if (isalnum(c)) {
            string op(1, c); // Creates a string of length 1 containing the character c. Converts a single character (like 'A') into a string ("A")
            s.push(op);
        }
        // If operator, pop two elements, form expression, and push back
        else {
            string op2 = s.top(); 
			s.pop();
            string op1 = s.top(); 
			s.pop();
            s.push("(" + op1 + c + op2 + ")");
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

    string infix = postfixToInfix(postfix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
