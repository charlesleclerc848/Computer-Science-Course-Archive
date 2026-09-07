#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}

float square(float f) {
    return f * f;
}

int main() {
    int n = 5;
    float f = 3.14;

    cout << "Square of " << n << " is " << square(n) << endl;
    cout << "Square of " << f << " is " << square(f) << endl;

    return 0;
}

