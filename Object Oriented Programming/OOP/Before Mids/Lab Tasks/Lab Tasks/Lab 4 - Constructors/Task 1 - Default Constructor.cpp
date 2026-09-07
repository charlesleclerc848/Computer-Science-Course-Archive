// C++ program to demonstrate the use of default constructor

#include <iostream>
using namespace std;

// declare a class
class  Noman {
  public:
    // default constructor 
    Noman() {
      cout << "SAP ID: 701233" << endl;
      cout << "Name: Noman";
    }
};

int main() {
  Noman n;
  return 0;
}
