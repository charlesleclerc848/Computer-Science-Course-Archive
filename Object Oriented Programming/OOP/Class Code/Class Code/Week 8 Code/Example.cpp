#include<iostream>
using namespace std;

class Person{
	protected:
	string name;
	int age;
	public:
		Person(int a, string n){
			age = a;
			name = n;
		}
};

class Employee{
	protected:
	int empID;
	string department;
	public:
		Employee(int eID, string d){
			empID = eID;
			department = d;
		}
};

class Manager:public Person, public Employee{
	string level;
	public:
		Manager(string lev, int a, string n, int i, string d):Person(a,n), Employee(i, d)
		{
			level = lev;
		}
		void displayManager(){
			cout<<"Employee ID = "<<empID<<endl;
			cout<<"Employee Name = "<<name<<endl;
			cout<<"Employee age = "<<age<<endl;
			cout<<"Employee department = "<<department<<endl;
			cout<<"Manager Level = "<<level<<endl;
		}
};

int main()
{
	Manager m("Junior", 24, "Ali Ahmad", 1001, "Computer Science");
	m.displayManager();
}









