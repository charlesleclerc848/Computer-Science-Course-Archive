#include<iostream>
using namespace std;

class vehicle{
	int model;
	string make;
	public:
		vehicle(int m, string mk)
		{
			model = m;
			make = mk;
		}
		
		void showDetails(){
			cout<<"Model = "<<model;
			cout<<"\nMake = "<<make<<endl;
		}
};

class car : public virtual vehicle{
	int numDoors;
	public:
		car(int d, int m, string mk):vehicle(m, mk){
			numDoors = d;
		}
		
		void showDetails(){
			
			cout<<"Number of doors = "<<numDoors<<endl;
		}
};

class truck : virtual public vehicle{
	int loadCapacity;
	public:
		truck(int c, int m, string mk):vehicle(m, mk){
			loadCapacity = c;
		}
		
		void showDetails(){
			
			cout<<"Load Capacity = "<<loadCapacity<<endl;
		}
};

class PickupTruck: public car, public truck{
	public:
		PickupTruck(int m, string mk, int d, int c):vehicle(m, mk), car(d, m, mk), truck(c, m, mk){
			
		}
		void showDetails(){
			vehicle::showDetails();
			car::showDetails();
			truck::showDetails();
		}
};

int main(){
	PickupTruck p1(2022, "Toyota", 4, 50);
	p1.showDetails();
}









