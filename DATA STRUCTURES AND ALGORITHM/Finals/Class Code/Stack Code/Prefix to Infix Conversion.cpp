#include <iostream>
#include <stack>
using namespace std;

// Function to convert prefix to infix
string prefixToInfix(string prefix) {
    stack<string> s;
    int i = prefix.length() - 1;

    while (i >= 0) {
        char c = prefix[i];

        // If operand, push to stack
        if (isalnum(c)) {
            string op(1, c);
            s.push(op);
        }
        // If operator, pop two elements, form expression, and push back
        else {
            string op1 = s.top(); 
			s.pop();
            string op2 = s.top(); 
			s.pop();
            s.push("(" + op1 + c + op2 + ")");
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

    string infix = prefixToInfix(prefix);
    cout << "Infix Expression: " << infix << endl;

    return 0;
}
