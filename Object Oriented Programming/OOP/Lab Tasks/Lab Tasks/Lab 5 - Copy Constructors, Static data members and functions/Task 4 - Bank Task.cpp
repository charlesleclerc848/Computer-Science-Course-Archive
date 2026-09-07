#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    static double interestRate;
    static int nextAccountNumber;

public:
    // Constructor
    BankAccount() {
        accountNumber = nextAccountNumber++;  // Assign account number and increment
        balance = 0.0;                       // Initialize balance to 0
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Invalid withdraw amount or insufficient balance.\n";
        }
    }

    // Method to calculate interest and add to balance
    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest of " << interest << " added to account " << accountNumber << endl;
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Getter for account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Static function to set interest rate for all accounts
    static void setInterestRate(double newRate) {
        if (newRate >= 0) {
            interestRate = newRate;
            cout << "Interest rate set to " << interestRate << "%" << endl;
        } else {
            cout << "Invalid interest rate.\n";
        }
    }
};

// Initialize static members
double BankAccount::interestRate = 2.0;  // Default interest rate (e.g., 2%)
int BankAccount::nextAccountNumber = 1000;  // First account number starts from 1000

int main() {
    // Create bank accounts
    BankAccount account1;
    BankAccount account2;

    // Perform operations
    account1.deposit(1000);
    account2.deposit(2000);

    // Withdraw money
    account1.withdraw(500);
    account2.withdraw(2500);  // Should show insufficient balance

    // Calculate interest
    account1.calculateInterest();
    account2.calculateInterest();

    // Show balances
    cout << "Account " << account1.getAccountNumber() << " balance: " << account1.getBalance() << endl;
    cout << "Account " << account2.getAccountNumber() << " balance: " << account2.getBalance() << endl;

    // Set a new interest rate for all accounts
    BankAccount::setInterestRate(3.5);

    // Calculate interest again with new interest rate
    account1.calculateInterest();
    account2.calculateInterest();

    // Show updated balances
    cout << "Account " << account1.getAccountNumber() << " balance: " << account1.getBalance() << endl;
    cout << "Account " << account2.getAccountNumber() << " balance: " << account2.getBalance() << endl;

    return 0;
}

