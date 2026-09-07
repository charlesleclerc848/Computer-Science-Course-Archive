#include <iostream>
#include <string>
using namespace std;

int main()
{
    string uname;
    string pass;

    cout << "\nEnter User Name  :  ";
    getline(cin, uname); // Read the full name with spaces
    cout << "\nEnter Password   :  ";
    getline(cin, pass);

    try
    {
        // Check password length
        if (pass.length() < 6)
        {
            throw string("Password must have at least 6 characters.");
        }

        // Check for at least one digit in the password
        bool digit_found = false;
        for (int i = 0; i < pass.length(); i++)
        {
            if (isdigit(pass[i]))
            {
                digit_found = true;
                break;
            }
        }

        if (!digit_found)
        {
            throw string("Password must contain at least one digit.");
        }

        // If all checks pass
        cout << "\nPassword is Correct";
    }
    catch (string err)
    {
        cout << "\nError: " << err;
    }
    catch (...)
    {
        cout << "\nDefault Exception";
    }

    return 0;
}
