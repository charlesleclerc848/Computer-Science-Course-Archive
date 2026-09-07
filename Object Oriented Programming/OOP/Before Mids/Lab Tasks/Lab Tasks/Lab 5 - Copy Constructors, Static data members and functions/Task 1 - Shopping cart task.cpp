#include <iostream>
using namespace std;

class ShoppingCart {
private:
    int cartID;
    double* totalPrice; // Pointer for total price

public:
    // Constructor
    ShoppingCart(int id, double price) {
        cartID = id;
        totalPrice = new double; // Dynamically allocate memory for total price
        *totalPrice = price;      // Assign the price
    }

    // Shallow copy constructor
    ShoppingCart(const ShoppingCart& other) {
        cartID = other.cartID;
        totalPrice = other.totalPrice; // Shallow copy of total price pointer
    }

    // Display method
    void display() {
        cout << "Cart ID: " << cartID << ", Total Price: " << *totalPrice << endl;
    }

    // Modify total price
    void modifyPrice(double newPrice) {
        *totalPrice = newPrice;
    }

    // Destructor
    ~ShoppingCart() {
        delete totalPrice; // Free the dynamically allocated memory
    }
};

int main() {
    int cartID;
    double price;

    cout << "Enter cart ID: ";
    cin >> cartID;
    cout << "Enter total price: ";
    cin >> price;

    // Create original shopping cart
    ShoppingCart originalCart(cartID, price);

    // Create shallow copy
    ShoppingCart shallowCopy = originalCart;

    // Get new price from the user to modify in the shallow copy
    double newPrice;
    cout << "Enter new total price for the shallow copy: ";
    cin >> newPrice;

    // Modify price in shallow copy
    shallowCopy.modifyPrice(newPrice);

    // Display both original and shallow copy
    cout << "\nOriginal Shopping Cart:\n";
    originalCart.display();

    cout << "\nShallow Copy Shopping Cart:\n";
    shallowCopy.display();

    return 0;
}

