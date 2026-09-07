#include <iostream>
#include <string>
using namespace std;

class IceCreamCone {
private:
    string flavour;
    int number_of_scoops;
    string cone_type;
    int price;
    static int total_cones_sold;

public:
    // Constructor with default values
    IceCreamCone(string f = "Vanilla", int scoops = 1, string cone = "Sugar") 
        : flavour(f), number_of_scoops(scoops), cone_type(cone) {
        
        // Calculate price
        price = 75 * number_of_scoops;
        if (cone_type == "Waffle") {
            price += 40;
        }
        
        // Increment static member for total cones sold
        total_cones_sold++;
    }

    // Static function to get total cones sold
    static int get_total_cones_sold() {
        return total_cones_sold;
    }

    // Function to display cone details
    void display() const {
        cout << "Flavour: " << flavour << ", Scoops: " << number_of_scoops 
             << ", Cone Type: " << cone_type << ", Price: " << price << " rupees\n";
    }
};

// Initialize static member
int IceCreamCone::total_cones_sold = 0;

int main() {
    // Create some IceCreamCone objects
    IceCreamCone cone1;
    IceCreamCone cone2("Chocolate", 2, "Waffle");
    IceCreamCone cone3("Strawberry", 3);

    // Display details of each cone
    cone1.display();
    cone2.display();
    cone3.display();

    // Display total cones sold
    cout << "Total cones sold: " << IceCreamCone::get_total_cones_sold() << endl;

    return 0;
}

