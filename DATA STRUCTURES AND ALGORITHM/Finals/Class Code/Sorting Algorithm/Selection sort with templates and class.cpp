#include <iostream>
#include <string>
using namespace std;

// Student class with id, name, and display() method
class Student {
public:
    int id;
    string name;

    // Constructor
    Student(int i, string n) : id(i), name(n) {}

    // Simple method to display student info
    void display() const {
        cout << name << " (" << id << ")";
    }

    // Overload '<' operator for sorting by id
    bool operator<(const Student &other) const {
        return this->id < other.id;
    }
};

// Template function for Selection Sort
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {  // Uses overloaded '<' operator
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);  // Swap elements
    }
}

// Template function to print an array using display()
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].display();  // Using display()
        cout << endl;
    }
    cout << endl;
}

// Main function to test sorting
int main() {
    // Creating an array of Student objects
    Student students[] = {
        {102, "Alice"},
        {101, "Bob"},
        {105, "Charlie"},
        {103, "David"}
    };
    int n = sizeof(students) / sizeof(students[0]);

    cout << "Before sorting:\n";
    printArray(students, n);

    selectionSort(students, n);

    cout << "After sorting by ID:\n";
    printArray(students, n);

    return 0;
}
