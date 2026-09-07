#include <iostream>
using namespace std;

// User-defined exception
class OutOfStockException {
    string message;
public:
    OutOfStockException(string msg) : message(msg) {}
    string what() {
        return message;
    }
};

class Inventory {
    string itemName;
    int quantity;
    double price;

public:
    Inventory(string name, int qty, double pr) : itemName(name), quantity(qty), price(pr) {}

    void sellItem(int qty) {
        if (qty > quantity) {
            throw OutOfStockException("Requested quantity exceeds available stock.");
        }
        quantity -= qty;
        cout << "Sale successful! Remaining stock of " << itemName << ": " << quantity << endl;
    }

    void displayStock() {
        cout << "Item: " << itemName << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }
};

int main() {
    Inventory item("Laptop", 10, 1500.00);

    item.displayStock();
    try {
        item.sellItem(12); // Trying to sell more than available stock
    } catch (OutOfStockException e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
