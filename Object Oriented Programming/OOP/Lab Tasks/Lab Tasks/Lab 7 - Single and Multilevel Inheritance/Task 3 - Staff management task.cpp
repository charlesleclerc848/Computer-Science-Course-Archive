#include <iostream>
using namespace std;

class Staff {
protected:
    string name;
    string role;

public:
    // Constructor for Staff class
    Staff(string n, string r) : name(n), role(r) {}

    // Display Staff details
    void displayStaff() {
        cout << "Name: " << name << ", Role: " << role << endl;
    }
};

class KitchenStaff : public Staff {
protected:
    string shift;     // e.g., morning, evening, night
    string section;   // e.g., bakery, grill

public:
    // Constructor for KitchenStaff class
    KitchenStaff(string n, string r, string s, string sec) 
        : Staff(n, r), shift(s), section(sec) {}

    // Display KitchenStaff details
    void displayKitchenStaff() {
        displayStaff();
        cout << "Shift: " << shift << ", Section: " << section << endl;
    }
};

class HeadChef : public KitchenStaff {
    string specialty;         // e.g., Italian cuisine
    int yearsOfExperience;    // years of experience as a chef

public:
    // Constructor for HeadChef class
    HeadChef(string n, string r, string s, string sec, string spec, int exp) 
        : KitchenStaff(n, r, s, sec), specialty(spec), yearsOfExperience(exp) {}

    // Display HeadChef's responsibilities
    void displayResponsibilities() {
        displayKitchenStaff();
        cout << "Specialty: " << specialty 
             << ", Years of Experience: " << yearsOfExperience << endl;
        cout << "Responsibilities: Oversees kitchen operations, manages staff, ensures food quality, "
             << "and creates menus specializing in " << specialty << "." << endl;
    }
};

// Main function to demonstrate the classes
int main() {
    // Create a HeadChef object
    HeadChef chef("John Doe", "Head Chef", "Morning", "Grill", "Italian Cuisine", 15);

    cout << "Head Chef Details:" << endl;
    chef.displayResponsibilities();

    return 0;
}

