#include<iostream>
using namespace std;

class Vehicle{
	protected:
		string FuelType;
	public:
		void setFuelType(string ft)
		{
			FuelType = ft;
		}
};

class Car : public Vehicle{
	protected:
		string brand;
};

class ElectricCar:public Car{
	public:
		void setBrand(string b)
		{
			brand = b;
		}
		void display()
		{
			cout<<"Brand = "<<brand<<endl;
			cout<<"Fuel type = "<<FuelType<<endl;
		}
};

int main(){
	ElectricCar c;
	c.setBrand("BMW");
	c.setFuelType("Patrol");
	c.display();
}









