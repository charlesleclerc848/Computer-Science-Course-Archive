#include <iostream>
using namespace std;

class A {
public:
    virtual void display() {
        cout << "Display from Class A" << endl;
    }
};

class B : public A {
public:
    void display() override {
        cout << "Display from Class B" << endl;
    }
};

class C : public B {
public:
    void display() override {
        cout << "Display from Class C" << endl;
    }
};

int main() {
    A* aPtr;
    C cObj;

    aPtr = &cObj;
    aPtr->display();

    return 0;
}
