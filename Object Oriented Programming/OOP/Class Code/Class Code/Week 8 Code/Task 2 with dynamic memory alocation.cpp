#include<iostream>
using namespace std;
class Room{
	string roomName;
	public:
		Room(){
		}
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
	Room* room[2];
	public:
		House(string hName, string r1, string r2){
			houseName = hName;
			room[0] = new Room(r1);
			room[1] = new Room(r2);
		}
		void displayHouse()
		{
			cout<<"House "<<houseName<<" has following rooms\n";
			cout<<"Room 1 = ";
			room[0]->displayRoom();
			cout<<"\nRoom 2 = ";
			room[1]->displayRoom();
		}
};

int main(){
	House h("Governer House", "Bedroom", "Dining Room");
	h.displayHouse();
}
