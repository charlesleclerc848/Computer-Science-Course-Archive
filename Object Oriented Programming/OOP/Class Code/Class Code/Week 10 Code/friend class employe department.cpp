#include<iostream>
using namespace std;
class Employee{
	int id, salary;
	string name;
	public:
		Employee(int i, int s, string n){
			id = i;
			salary = s;
			name = n;
		}
		
		friend class Department;
};

class Department{
	string dName;
	public:
		Department(string d){
			dName = d;
		}
		
		void display(Employee &e)
		{
			cout<<"Department = "<<dName<<endl;
			cout<<"Employee ID = "<<e.id<<endl;
			cout<<"Employee name = "<<e.name<<endl;
			cout<<"Employee salary = "<<e.salary<<endl;
		}
};

int main(){
	Employee e1(1, 5000, "Umair");
	Department d("CS");
	
	d.display(e1);
}












