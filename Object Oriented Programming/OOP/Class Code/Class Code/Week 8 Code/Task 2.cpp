#include<iostream>
using namespace std;
class Room{
	string roomName;
	public:
		Room(string n)
		{
			roomName = n;
		}
		void displayRoom(){
			cout<<roomName;
		}
};

class House{
	string houseName;
	Room room1;
	Room room2;
	public:
		House(string hName, string r1, string r2):room1(r1), room2(r2){
			houseName = hName;
		}
		void displayHouse()
		{
			cout<<"House "<<houseName<<" has following rooms\n";
			cout<<"Room 1 = ";
			room1.displayRoom();
			cout<<"\nRoom 2 = ";
			room2.displayRoom();
		}
};

int main(){
	House h("Governer House", "Bedroom", "Dining Room");
	h.displayHouse();
}
