#include <iostream>
using namespace std;
class Employee{
	protected:
		string firstName;
		string lastName;
		public:
			Employee(string first , string last){
				firstName=first;
				lastName=last;
				
			}
		virtual float earning()=0;
		virtual void print()=0;
		
		virtual ~Employee(){
		}
		 
};
class Salaried:public Employee{
protected:
	float fixed_salary;
public:
	Salaried(float fixed,string first, string last):Employee(first,last)
	{
		fixed_salary = fixed;	
	}	
	float earning() override{
		return fixed_salary;
	}
	void print() override{
		cout<<"Employee first name :"<<firstName<<endl;
		cout<<"Employee second name :"<<lastName<<endl;
	}
};
class HourlyWorker:public Employee{
	protected:
		int hours;
		int salaryPerHour;
	public:
		HourlyWorker(int h, int s,string first, string last):Employee(first,last){
			hours=h;
			salaryPerHour=s;
		}
		float earning() override{
			return hours*salaryPerHour;
		}
		void print() override{
		cout<<"Employee first name :"<<firstName<<endl;
		cout<<"Employee second name :"<<lastName<<endl;
	}	
};
class comissionedWorker:public Employee{
	protected:
		int sales;
		int salecomission;
	public:
		comissionedWorker(int s, int sc,string first, string last):Employee(first,last){
			sales=s;
			salecomission=sc;
		}
		float earning() override{
			return sales*salecomission;
		}
		void print() override{
		cout<<"Employee first name :"<<firstName<<endl;
		cout<<"Employee second name :"<<lastName<<endl;
	}	
};

class basePlusCommission:public comissionedWorker{
	protected:
		float baseSalary;
	public:
		basePlusCommission(float bSalary, int s, int sc, string first, string last):comissionedWorker(s, sc, first,last){
			baseSalary=bSalary;
		}
		float earning() override{
			return baseSalary+comissionedWorker::earning();
		}
		void print() override{
		cout<<"Employee first name :"<<firstName<<endl;
		cout<<"Employee second name :"<<lastName<<endl;
	}	
};
int main(){
	Salaried salary(9000.90, "Ali", "Ahmad");
	HourlyWorker hworker(300, 200, "Imran", "Ahmad");
	comissionedWorker cworker(30, 500, "Naveed", "Khan");
	basePlusCommission baseWorker(8000, 50, 300, "Noman", "Khan");
	
	Employee * e[] = {&salary, &hworker, &cworker, &baseWorker};
	int arraysize = sizeof(e)/sizeof(e[0]);
	for(int i=0; i<arraysize; i++){
		e[i]->print();
		cout<<e[i]->earning()<<endl;
	}
}










