#include<iostream>
using namespace std;
inline double cube(double s)
{
	return s*s*s;
}
int main(){
	cout<<"Enter the side length of your cube: ";
	double side;
	cin>>side;
	cout<<"Volume of the cube with side "<<side<<" is : "<<cube(side)<<endl;
	return 0;
}
