#include <iostream>
using namespace std;

// Base class for general expenses
class Expense {
protected:
    double amount;
    string date;
    string description;

public:
    // Constructor for Expense class
    Expense(double amt, string dt, string desc) 
        : amount(amt), date(dt), description(desc) {}

    // Method to display expense details
    void displayExpense() {
        cout << "Amount: $" << amount << ", Date: " << date 
             << ", Description: " << description << endl;
    }
};

// Derived class for food-specific expenses
class FoodExpense : public Expense {
    string mealType;  // e.g., breakfast, lunch, dinner
    string location;  // e.g., home, restaurant

public:
    // Constructor for FoodExpense class
    FoodExpense(double amt, string dt, string desc, string meal, string loc) 
        : Expense(amt, dt, desc), mealType(meal), location(loc) {}

    // Method to display food expense details
    void displayFoodExpense() {
        displayExpense();
        cout << "Meal Type: " << mealType << ", Location: " << location << endl;
    }
};

// Main function to demonstrate the classes
int main() {
    // Create a FoodExpense object
    FoodExpense expense1(15.50, "2024-11-06", "Lunch with friends", "Lunch", "Restaurant");

    cout << "Expense Details:" << endl;
    expense1.displayFoodExpense();

    return 0;
}

