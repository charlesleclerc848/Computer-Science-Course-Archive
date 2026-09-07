#include<iostream>
using namespace std;
class Employee{
	protected:
		string name;
		int id;
	public:
		Employee(int i, string n){
			id = i;
			name = n;
		}
		void display(){
			cout<<"ID = "<<id<<endl;
			cout<<"Name = "<<name<<endl;
		}
};

class FullTimeEmployee: public Employee{
	protected:
		int baseSalary;
	public:
		FullTimeEmployee(int bs, int i, string n):Employee(i, n)
		{
			baseSalary = bs;
		}
		void displayBaseSalary(){
			cout<<"Base Salary = "<<baseSalary<<endl;
		}
};

class Manager:public FullTimeEmployee{
	int bonus;
	public:
		Manager(int b, int bs, int i, string n):FullTimeEmployee(bs, i, n)
		{
			bonus = b;
		}
		void totalSalary(){
			display();
			cout<<"Total salary = "<<baseSalary+bonus<<endl;
		}
};

int main(){
	Manager m(1000, 50000, 1, "Ali");
//	m.display();
	m.displayBaseSalary();
	m.totalSalary();
}









