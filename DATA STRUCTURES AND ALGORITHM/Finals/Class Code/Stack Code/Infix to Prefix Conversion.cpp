#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to prefix
string infixToPrefix(string infix) {
    stack<char> s;
    string prefix = "";
    int i = infix.length() - 1; // Start from the right

    while (i >= 0) {
        char c = infix[i];

        // If character is operand, add to prefix
        if (isalnum(c)) {
            prefix = c + prefix;
        }
        // If character is ')', push to stack
        else if (c == ')') {
            s.push(c);
        }
        // If character is '(', pop until ')' is found
        else if (c == '(') {
            while (!s.empty() && s.top() != ')') {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.pop(); // Remove ')'
        }
        // If character is an operator
        else {
            while (!s.empty() && precedence(s.top()) > precedence(c)) {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.push(c);
        }
        i--; // Move to previous character
    }

    // Pop remaining operators from stack
    while (!s.empty()) {
        prefix = s.top() + prefix;
        s.pop();
    }

    return prefix;
}

// Main function
int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
