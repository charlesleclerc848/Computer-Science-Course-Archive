#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    BankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    void displayBalance() const {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    friend void transferFunds(BankAccount& from, BankAccount& to, double amount);
};

void transferFunds(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << "." << endl;
    } else {
        cout << "Insufficient funds in Account " << from.accountNumber << "." << endl;
    }
}

int main() {
    BankAccount account1(101, 500.0);
    BankAccount account2(102, 300.0);

    cout << "Initial Balances:" << endl;
    account1.displayBalance();
    account2.displayBalance();

    transferFunds(account1, account2, 200.0);

    cout << "\nBalances After Transfer:" << endl;
    account1.displayBalance();
    account2.displayBalance();

    return 0;
}

