#include<iostream>
using namespace std;
class Vehicle{
	protected:
		string fuelType;
	public:
		void setFuelType(string type)
		{
			fuelType = type;
		}
};

class Car:public Vehicle{
	protected:
		string brand;
	public:
		void setBrand(string b)
		{
			brand = b;
		}
};

class ElectricCar:public Car{
	public:
		void showDetails()
		{
			cout<<"Fuel Type = "<<fuelType<<endl;
			cout<<"Brand Name = "<<brand;
		}
};

int main(){
	ElectricCar ec;
	ec.setBrand("Honda");
	ec.setFuelType("Patrol");
	ec.showDetails();
}






