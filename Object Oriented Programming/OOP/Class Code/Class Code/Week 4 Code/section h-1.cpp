#include<iostream>
using namespace std;

class Car{
	int model;
	string brand;
	string color;
	
	public:
		Car(){
			cout<<"Default Constructor called\n";
		}
		Car(int model, string brand, string color)
		{
			this->model = model;
			this->brand = brand;
			this->color = color;
			cout<<"Constructor called\n";	
		}
		void display()
		{
			cout<<"Brand = "<<brand<<endl;
			cout<<"Model = "<<model<<endl;
			cout<<"Color = "<<color<<endl;
		}
		
		~Car(){
			cout<<"Destructor called\n";
		}
};


int main()
{
	Car c1(2022, "BMW", "Pink");
//	Car c2;
	c1.display();
//	c2.display();
}














