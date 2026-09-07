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

    // Overload '>' operator for sorting by id
    bool operator>(const Student &other) const {
        return this->id > other.id;
    }
};

// Template function for Insertion Sort
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        // Move elements greater than key one step ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Template function to print an array using display()
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i].display();
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

    insertionSort(students, n);

    cout << "After sorting by ID (Insertion Sort):\n";
    printArray(students, n);

    return 0;
}
