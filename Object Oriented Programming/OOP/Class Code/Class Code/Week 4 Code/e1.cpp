#include<iostream>
using namespace std;
class Car{
	int model;
	string color;
	string brand;
	public:
		Car(int model, string color, string brand){
			this->model = model;
			this->color = color;
			this->brand = brand;
		}
		void display(){
			cout<<"Brand = "<<brand<<endl;
			cout<<"Model = "<<model<<endl;
			cout<<"Color = "<<color<<endl;
		}
};
int main()
{
	Car c1(2022, "Pink", "BMW");
	Car c2(2023, "Black", "Toyota");
	Car *ptr;
	ptr = &c1;
	c1.display();
	(*ptr).display();
	ptr->display();
	
	Car &ref = c1;
	
	ref.display();
	
	return 0;
}














