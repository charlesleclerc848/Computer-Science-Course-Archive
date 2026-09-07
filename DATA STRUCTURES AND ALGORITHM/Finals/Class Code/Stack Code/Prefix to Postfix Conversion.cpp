#include <iostream>
#include <stack>
using namespace std;

// Function to convert Prefix to Postfix
string prefixToPostfix(string prefix) {
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        // If operand, push it as a string
        if (isalnum(c)) {
            string op(1, c);
            s.push(op);
        } 
        // If operator, pop two operands and form a postfix expression
        else {
            string op1 = s.top(); 
			s.pop();
            string op2 = s.top(); 
			s.pop();
            string temp = op1 + op2 + c;
            s.push(temp);
        }
    }
    return s.top();  // Final Postfix expression
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;
    return 0;
}
