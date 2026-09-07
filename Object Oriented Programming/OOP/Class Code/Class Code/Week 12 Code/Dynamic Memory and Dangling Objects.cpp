#include <iostream>
using namespace std;

class Test {	
	public:	
	int a = 10;
    Test() {
        cout << "Object created." << endl;
    }
    ~Test() {
        cout << "Object destroyed." << endl;
    }
};

int main() {
    Test* obj = new Test(); // Dynamic allocation
    delete obj; // Object destroyed, obj is now dangling
	obj = nullptr; // Fix the dangling pointer
    cout<<obj->a; // Uncommenting this will cause undefined behavior
    return 0;
}
