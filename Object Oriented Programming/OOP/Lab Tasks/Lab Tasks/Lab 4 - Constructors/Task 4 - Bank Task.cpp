#include<iostream>
using namespace std;

class bank
{
	private :
		string name;
		double money;
		string account;

	public :
		bank(string n1 , double m , string a)
		{
			name=n1;
			money=m;
			account=a;
		}
		
		void deposit(double amount)
		{
			money=money+amount;
			cout<<"Now Balance is : "<<money<<endl;
		}
		
		void withdraw(double amount)
		{
			money=money-amount;
			cout<<"Withdraw\n";
			cout<<"Now Balance is : "<<money<<endl;
		}
		
		void dispaly()
		{
			cout<<"Name : "<<name<<endl;
			cout<<"Balance : "<<money<<endl;
			cout<<"Acount # : "<<account<<endl;
		}
};

int main()
{
	double amount;
	bank mine("Ahmad", 100.34, "HBL123");
	mine.dispaly();
	cout<<"Enter  The amount to deposit : ";
	cin>>amount;
	mine.deposit(amount);
	cout<<"Enter  The amount to withdraw : ";
	cin>>amount;
	mine.withdraw(amount);
	
	cout<<"Dispaly Function \n";
	mine.dispaly();
}

