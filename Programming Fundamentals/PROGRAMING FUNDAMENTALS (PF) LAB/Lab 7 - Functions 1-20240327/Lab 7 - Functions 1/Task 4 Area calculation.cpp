#include <iostream>
using namespace std;
double area(int);
int main()
{
	int radius;
	cout<<"Enter radius of a circle: ";
	cin>>radius;
	double a = area(radius);
	cout<<"Area = "<<a;
	return 0;
}

double area(int rad)
{
	double aa = 3.142* rad* rad;
	return aa;
}
