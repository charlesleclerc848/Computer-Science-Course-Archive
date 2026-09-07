#include<iostream>
using namespace std;

class Car{
	public:
	string brand;
	int model;
	string color;
	
	Car()
	{
	}
	Car(string b, int m, string c){
		brand = b;
		model = m;
		color = c;
	}
	
	void display()
	{
		cout<<"Brand = "<<brand<<endl;
		cout<<"Model = "<<model<<endl;
		cout<<"Color = "<<color<<endl;
	}
	
};

int main()
{
	Car c1,c2;
	Car *ptr = &c1;
	Car &ref = c1;
	ptr->color = "Green";
	ptr->model = 2022;
	ptr->brand = "Suzuki";
	ptr = &c2;
	c1.display();
}














