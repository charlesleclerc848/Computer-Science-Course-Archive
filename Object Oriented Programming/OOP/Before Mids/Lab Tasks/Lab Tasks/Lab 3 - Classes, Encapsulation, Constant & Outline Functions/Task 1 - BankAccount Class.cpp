#include<iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    void setAccountDetails(int accNum, double bal, string name) {
        accountNumber = accNum;
        balance = bal;
        accountHolderName = name;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }
};

int main() {
    BankAccount account;
    account.setAccountDetails(12345, 1000.50, "John Doe");

    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Account Holder: " << account.getAccountHolderName() << endl;
    cout << "Balance: $" << account.getBalance() << endl;

    return 0;
}

