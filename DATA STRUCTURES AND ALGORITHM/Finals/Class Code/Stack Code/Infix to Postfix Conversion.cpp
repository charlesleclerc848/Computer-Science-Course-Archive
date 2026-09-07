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

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    int i = 0;

    while (i < infix.length()) {
        char c = infix[i];

        // If character is operand, add to output
        if (isalnum(c)) {
            postfix += c;
        } 
        // If character is '(', push to stack
        else if (c == '(') {
            s.push(c);
        } 
        // If character is ')', pop until '(' is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Remove '('
        } 
        // If character is an operator
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
        i++; // Move to next character
    }

    // Pop remaining operators from stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Main function to take user input and convert to postfix
int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
