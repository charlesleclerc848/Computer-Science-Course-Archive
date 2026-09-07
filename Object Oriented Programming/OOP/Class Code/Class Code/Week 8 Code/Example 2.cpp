#include<iostream>
using namespace std;

class Person{
	protected:
		int age;
		string name;
	public:
		Person(){
		}
		Person(int a, string n){
			age = a;
			name = n;
		}
		void displayPerson()
		{
			cout<<"Student age = "<<age<<endl;
			cout<<"Student name = "<<name<<endl;
		}
};

class Student:public Person{
	protected:
		int stdID;
		string degree;
	public:
		Student(int i, string d, string n, int a): Person(a,n){
			stdID = i;
			degree = d;
		}
		void displayStudent(){
			cout<<"Student id = "<<stdID<<endl;
			cout<<"Student degree = "<<degree<<endl;
			displayPerson();
		}
};

class Instructor:public Person{
	protected:
		int empID;
		string department;
	public:
		Instructor(int eID, string dept){
			empID = eID;
			department = dept;
		}
		void displayInstructor(){
			cout<<"Employee id = "<<empID<<endl;
			cout<<"Department = "<<department<<endl;
		}
};

class TeachingAssistant: public Student, public Instructor{
	public:
		TeachingAssistant(int i, int a, string n, string d, int eID, string dept): Student(i,d,n,a), Instructor(eID, dept){
			
		}
		void displayAllDetails(){
			displayStudent();
			displayInstructor();			
		}
};

int main(){
	TeachingAssistant ta(7012, 20, "Ranjha", "BSCS", 1001, "CS");
	ta.displayAllDetails();
}











