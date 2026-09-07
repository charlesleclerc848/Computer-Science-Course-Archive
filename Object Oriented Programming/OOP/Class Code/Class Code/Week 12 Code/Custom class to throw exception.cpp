#include <iostream>
using namespace std;

// User-defined exception class
class DivideByZeroException {
private:
    string message;

public:
    DivideByZeroException() : message("Error: Division by zero is not allowed!") {}

    // Function to get the exception message
    string what() const {
        return message;
    }
};

// Function to perform division
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw DivideByZeroException(); // Throw user-defined exception
    }
    return numerator / denominator;
}

int main() {
    double num, den;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    try {
        // Attempt division
        double result = divide(num, den);
        cout << "Result: " << result << endl;
    }
    catch (const DivideByZeroException &e) {
        // Handle user-defined exception
        cout << e.what() << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
}
