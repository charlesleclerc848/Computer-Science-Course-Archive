#include<iostream>
using namespace std;

class Employee{
	int sapID;
	int salary;
	string name;
	
	public:
		Employee(){
		}
		Employee(int id, int s, string n)
		{
			sapID = id;
			salary = s;
			name = n;
		}
		
		void display()
		{
			cout<<"SAP ID = "<<sapID<<endl;
			cout<<"Salary = "<<salary<<endl;
			cout<<"Name = "<<name<<endl;
		}
	
};

int main()
{
	Employee *ptr = new Employee[3] {
		Employee(1,22,"ALI"), 
		Employee(2,33,"XYZ"),
		Employee(3,44,"ABC")
	};
	
	for(int i=0;i<3; i++)
	{
		(ptr+i)->display();
	}
	for(int i=0;i<3; i++)
	{
		delete[] ptr;
	}
}









