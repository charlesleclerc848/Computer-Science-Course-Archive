#include<iostream>
using namespace std;

class Employee{
	int id;
	string name;
	protected:
	int salary;
	public:
		Employee(int i, string n, int s){
			id = i;
			name = n;
			salary = s;
		}
		
		void displayEmployee(){
			cout<<"ID = "<<id<<endl;
			cout<<"Name = "<<name<<endl;
			cout<<"Salary = "<<salary<<endl;
		}
};

class Teacher:public Employee{
	int bonus;
	string department;
	string subject;
	public:
		Teacher(int b, string d, string s, int i, string n, int ss):Employee(i,n,ss)
		{
			bonus = b;
			department = d;
			subject = s;
		}
		void displayTeacher(){
			displayEmployee();
			cout<<"Bonus = "<<bonus<<endl;
			cout<<"Department = "<<department<<endl;
			cout<<"Subject = "<<subject<<endl;
			cout<<"Total Salary = "<<salary+bonus<<endl;
		}
};

int main(){
	Teacher t1(1000, "CS", "OOP", 1, "Ali", 50000);
//	t1.displayEmployee();
	t1.displayTeacher();
}










