#include <iostream>
#include <string>
using namespace std;

// Template class for WarehouseInventory
template <typename TWeight, typename TQuantity>
class WarehouseInventory {
private:
    string itemName;
    TWeight itemWeight;
    TQuantity itemQuantity;

public:
    // Function to set item details
    void setItemDetails(string name, TWeight weight, TQuantity quantity) {
        itemName = name;
        itemWeight = weight;
        itemQuantity = quantity;
    }

    // Function to calculate total inventory weight
    TWeight calculateTotalWeight() {
        return itemWeight * itemQuantity;
    }

    // Function to display inventory details
    void displayDetails() {
        cout << "Item Name: " << itemName << endl;
        cout << "Item Weight: " << itemWeight << endl;
        cout << "Item Quantity: " << itemQuantity << endl;
        cout << "Total Inventory Weight: " << calculateTotalWeight() << endl;
    }
};

int main() {
    // Create a WarehouseInventory object for double weight and int quantity
    WarehouseInventory<double, int> inventory1;
    inventory1.setItemDetails("Steel Rod", 12.5, 100);
    cout << "Inventory 1 Details:" << endl;
    inventory1.displayDetails();

    cout << endl;

    // Create a WarehouseInventory object for float weight and double quantity
    WarehouseInventory<float, double> inventory2;
    inventory2.setItemDetails("Cement Bag", 50.0f, 35.5);
    cout << "Inventory 2 Details:" << endl;
    inventory2.displayDetails();

    return 0;
}
