#include <iostream>
#include <cstring> // For strcpy
using namespace std;

class Movie {
private:
    string title;
    float* rating; // Pointer for rating

public:
    // Constructor
    Movie(string t, float r) {
        title = t;
        rating = new float; // Dynamically allocate memory for rating
        *rating = r;        // Assign the rating
    }

    // Deep copy constructor
    Movie(const Movie& other) {
        title = other.title;
        rating = new float; // Allocate new memory for rating
        *rating = *other.rating; // Copy the rating value
    }

    // Display method
    void display() {
        cout << "Title: " << title << ", Rating: " << *rating << endl;
    }

    // Modify rating
    void modifyRating(float newRating) {
        *rating = newRating;
    }

    // Destructor
    ~Movie() {
        delete rating; // Free the dynamically allocated memory
    }
};

int main() {
    string title;
    float rating;

    cout << "Enter movie title: ";
    getline(cin, title); // Use getline to allow spaces in the title
    cout << "Enter movie rating: ";
    cin >> rating;

    // Create original movie
    Movie originalMovie(title, rating);

    // Create deep copy
    Movie deepCopy = originalMovie;

    // Modify rating in deep copy
    float newRating;
    cout << "Enter new rating for the deep copy: ";
    cin >> newRating;
    deepCopy.modifyRating(newRating);

    // Display both original and deep copy
    cout << "\nOriginal Movie:\n";
    originalMovie.display();

    cout << "\nDeep Copy Movie:\n";
    deepCopy.display();

    return 0;
}

