#include<iostream>
using namespace std;
class InsufficientBalance{
	string message;
	public:
		InsufficientBalance(string msg){
			message = msg;
		}
		string what(){
			return message;
		}
};

class BankAccount{
	double balance;
	public:
		BankAccount(double b){
			balance = b;
		}	
		void withdraw(double amount){
			if(amount>balance){
				throw InsufficientBalance("Insuffcient account balance.");
			}
			balance = balance - amount;
			cout<<"Withdraw successfull and remaining balance is : "<<balance<<endl;
		}
};

int main(){
	BankAccount acc1(5000.50);
	try{
		acc1.withdraw(600);
	}
	catch(InsufficientBalance i){
		cout<<"Error : "<<i.what();
	}
}














