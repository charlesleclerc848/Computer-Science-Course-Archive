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
//	Employee e[3]={Employee(11, 1000, "Majid"),
//	Employee(11, 1000, "Ali"),
//	Employee(11, 1000, "Noman")};

	int id, salary;
	string name;
	
	Employee e[3];
	
	for(int j=0; j<3; j++)
	{
		cout<<"Enter sap id = ";
		cin>>id;
		cout<<"Enter salary = ";
		cin>>salary;
		cout<<"Enter name = ";
		cin>>name;
		
		e[j] = Employee(id, salary, name);
	}
	
	for(int i=0; i<3; i++)
	{
		e[i].display();
	}
}









