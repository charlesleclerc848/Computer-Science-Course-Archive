#include <iostream>

using namespace std;

int main()
{
    double salary, tax, netSalary;

    // Prompt user to enter salary
    cout << "Enter the salary: ";
    cin >> salary;

    // Calculate tax amount and net salary based on salary and tax policy
    if (salary <= 7500)
    {
        tax = 0;
        netSalary = salary;
    }
    else if (salary >= 7501 && salary < 15000)
    {
        tax = 0.05 * salary;
        netSalary = salary - tax;
    }
    else if (salary >= 15000 && salary < 25000)
    {
        tax = 0.12 * salary;
        netSalary = salary - tax;
    }
    else if (salary >= 25000 && salary < 50000)
    {
        tax = 0.18 * salary;
        netSalary = salary - tax;
    }
    else if (salary >= 50000 && salary < 150000)
    {
        tax = 0.24 * salary;
        netSalary = salary - tax;
    }
    else // salary >= 150000
    {
        tax = 0.27 * salary;
        netSalary = salary - tax;
    }

    // Display the tax and net salary
    cout << "Tax: " << tax << endl;
    cout << "Net salary: " << netSalary << endl;

    return 0;
}

