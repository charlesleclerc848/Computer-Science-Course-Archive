#include<iostream>
using namespace std;

class employee
{
	protected:
		string firstname;
		string lastname;
	public:
		employee(string a,string b)
		{
			firstname=a;
			lastname=b;		
		}
		
		virtual float earning()=0;
		virtual void print()=0;
};
class salariedemployee :public employee
{
	protected:
		float salary;
		public:
			salariedemployee(string a,string b,float s):employee(a,b){
				salary=s;
			}
		float earning() override{
			return salary;
		}
		void print() override{
			cout<<"First name is "<<firstname<<endl;
			cout<<"Last name is "<<lastname<<endl;
		}
		
		virtual void show() = 0;
};

class hourlyEmployees :public employee
{
	protected:
		int hoursWorked;
		float hourlyWage;
		public:
			hourlyEmployees(string a,string b,int h, float w):employee(a,b){
				hoursWorked = h;
				hourlyWage = w;
			}
		float earning() override{
			if(hoursWorked>0 and hoursWorked<=168){
				return hoursWorked * hourlyWage;
			}
			else
			{
				return 0;
			}
		}
		void print() override{
			cout<<"First name is "<<firstname<<endl;
			cout<<"Last name is "<<lastname<<endl;
		}
};

class commissionEmployees :public employee
{
	protected:
		float commissionRate;
		int sales;
		public:
			commissionEmployees(string a,string b,float c, int s):employee(a,b){
				commissionRate = c;
				sales = s;
			}
		float earning() override{
			if(commissionRate>0 and sales>0){
				return sales * commissionRate;
			}
			else
			{
				return 0;
			}
		}
		void print() override{
			cout<<"First name is "<<firstname<<endl;
			cout<<"Last name is "<<lastname<<endl;
		}
};

class basePlusCommissionEmployees :public commissionEmployees
{
	protected:
		float baseSalary;
		public:
			basePlusCommissionEmployees(string a,string b,float c, int s, float bSalary):commissionEmployees(a, b, c, s){
				baseSalary = bSalary;
			}
		float earning() override{
			if(baseSalary>0){
				return baseSalary + commissionEmployees::earning();
			}
			else
			{
				return 0;
			}
		}
		void print() override{
			cout<<"First name is "<<firstname<<endl;
			cout<<"Last name is "<<lastname<<endl;
		}
};

int main(){
	salariedemployee salaried("Ali", "Ahmad", 5000.50);
	hourlyEmployees hourly("Mehran", "Ahmad", 2, 500.0);
	commissionEmployees commission("Rafay", "Rana", 300.0, 100);
	basePlusCommissionEmployees basePlus("Hafiz", "Moiz", 500.0, 120, 6000.90);
	
	employee * e[] = {&salaried, &hourly, &commission, &basePlus};
	
	int arraySize = sizeof(e) / sizeof(e[0]);
	
	for(int i=0; i<arraySize; i++){
		e[i]->print();
		cout<<e[i]->earning()<<endl;
	}
}












