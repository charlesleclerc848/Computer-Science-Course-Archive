#include<iostream>
using namespace std;
class Employee{
	protected:
		int id;
		string name;
	public:
		Employee(int i, string n)
		{
			id = i;
			name = n;
		}
		void display()
		{
			cout<<"ID = "<<id<<endl;
			cout<<"Name = "<<name<<endl;
		}
};

class FullTimeEmployee:public Employee{
	protected:
		int baseSalary;
	public:
		FullTimeEmployee(int bs, int idd, string namee):Employee(idd,namee)
		{
			baseSalary = bs;
		}
		void displayBaseSalary()
		{
			cout<<"Base salary = "<<baseSalary<<endl;
		}
};

class Manager:public FullTimeEmployee{
	int bonus;
	public:
		Manager(int b, int bs, int i, string n):FullTimeEmployee(bs, i, n)
		{
			bonus = b;
		}
		void displayTotalSalary(){
			display();
			displayBaseSalary();
			cout<<"Total Salary = "<<baseSalary+bonus;
		}
};

int main()
{
	Manager m(1000, 50000, 70332, "Ali");
//	m.display();
//	m.displayBaseSalary();
	m.displayTotalSalary();
	
}







