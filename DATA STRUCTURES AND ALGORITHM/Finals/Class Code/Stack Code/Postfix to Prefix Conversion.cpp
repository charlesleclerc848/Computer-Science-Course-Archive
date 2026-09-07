#include <iostream>
#include <stack>
using namespace std;

// Function to convert Postfix to Prefix
string postfixToPrefix(string postfix) {
    stack<string> s;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        // If operand, push it as a string
        if (isalnum(c)) {
            string op(1, c);
            s.push(op);
        } 
        // If operator, pop two operands and form a prefix expression
        else {
            string op1 = s.top(); 
			s.pop();
            string op2 = s.top(); 
			s.pop();
            string temp = c + op2 + op1;
            s.push(temp);
        }
    }
    return s.top();  // Final Prefix expression
}

int main() {
    string postfix;
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;
    return 0;
}
