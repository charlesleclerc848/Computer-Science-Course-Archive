#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    T1 first; // First data member of type T1
    T2 second; // Second data member of type T2

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    
    // Function to display both members
    void display() {
        cout << "First: " << first << ", Second: " << second << endl;
    }

    // Function to set new values
    void setValues(T1 f, T2 s) {
        first = f;
        second = s;
    }
};

int main() {
    Pair<int, string> p1(42, "Hello");
    p1.display();

    p1.setValues(100, "World");
    p1.display();

    return 0;
}
