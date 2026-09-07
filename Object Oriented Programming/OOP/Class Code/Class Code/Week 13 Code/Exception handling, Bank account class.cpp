#include <iostream>
using namespace std;

// User-defined exception
class InsufficientFundsException {
    string message;
public:
    InsufficientFundsException(string msg) : message(msg) {}
    string what() {
        return message;
    }
};

class BankAccount {
    double balance;
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException("Insufficient funds for withdrawal.");
        }
        balance -= amount;
        cout << "Withdrawal successful! New balance: $" << balance << endl;
    }

    void displayBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account(1000);

    account.displayBalance();
    try {
        account.withdraw(1200); // Attempting to withdraw more than the balance
    } catch (InsufficientFundsException e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
