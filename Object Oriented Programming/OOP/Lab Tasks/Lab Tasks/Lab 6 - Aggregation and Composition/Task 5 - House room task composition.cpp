#include <iostream>
using namespace std;

class Room {
public:
    string name;

    Room(string name) : name(name) {
        cout << "Room " << name << " created." << endl;
    }
    ~Room() {
        cout << "Room " << name << " destroyed." << endl;
    }
};

class House {
public:
    string address;
    Room room1;
    Room room2;

    House(string address, string room1Name, string room2Name) 
        : address(address), room1(room1Name), room2(room2Name) {
        cout << "House at " << address << " created." << endl;
    }
    ~House() {
        cout << "House at " << address << " destroyed." << endl;
    }

    void showRooms() {
        cout << "House at " << address << " has rooms: " << room1.name << " and " << room2.name << "." << endl;
    }
};

int main() {
    House house("123 Maple St", "Living Room", "Bedroom");
    house.showRooms();

    return 0;
}

