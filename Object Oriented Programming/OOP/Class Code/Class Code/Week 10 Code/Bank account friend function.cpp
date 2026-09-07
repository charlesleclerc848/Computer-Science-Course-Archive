#include<iostream>
using namespace std;
class BankAccount{
	int accountNo, balance;
	public:
		BankAccount(int accNo, int b){
			accountNo = accNo;
			balance = b;
		}
		void display()
		{
			cout<<"Account number = "<<accountNo<<endl;
			cout<<"Account balance = "<<balance<<endl;
		}
		friend void transferFunds(BankAccount &from, BankAccount &to, int amount);
};

void transferFunds(BankAccount &from, BankAccount &to, int amount)
{
	if(from.balance >= amount){
		from.balance = from.balance - amount;
		to.balance = to.balance + amount;
		cout<<"Transfer successfull"<<endl;
	}
	else
	{
		cout<<"Insufficient balance"<<endl;
	}
}

int main()
{
	BankAccount a1(1001, 5000);
	BankAccount a2(1002, 3000);
	
	a1.display();
	a2.display();
	
	transferFunds(a1, a2, 1000);
	
	a1.display();
	a2.display();
}













