#include<iostream>
using namespace std;
int main()
{
	double grad;
	double sal,bonus;
	cout<<"Enter salary : ";
	cin>>sal;
	cout<<"Enter grade : ";
	cin>>grad;
	if (grad > 15)
	{
		bonus = sal*(50.0/100.0);
		cout<<"Total salary with 50 percent bonus : "<<(bonus+sal)<<endl;
	}
	else
	{
		bonus = sal* (25.0/100.0);
		cout<<"Total salary with 25 percent bonus : "<<(bonus+sal)<<endl;
	}
	return 0;
}
