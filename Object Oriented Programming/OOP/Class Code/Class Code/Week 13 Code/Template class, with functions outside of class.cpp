#include <iostream>
using namespace std;

// Template class declaration
template <typename T>
class SimpleClass {
    T data; // Data member
public:
    SimpleClass(T value); // Constructor declaration
    void display();       // Function declaration
};

// Constructor definition outside the class
template <typename T>
SimpleClass<T>::SimpleClass(T value) : data(value) {}

// Function definition outside the class
template <typename T>
void SimpleClass<T>::display() {
    cout << "Data: " << data << endl;
}

// Main function to test the template class
int main() {
    SimpleClass<int> obj1(42);     // Instantiate with int
    obj1.display();               // Output: Data: 42

    SimpleClass<string> obj2("Hello"); // Instantiate with string
    obj2.display();                   // Output: Data: Hello

    return 0;
}
