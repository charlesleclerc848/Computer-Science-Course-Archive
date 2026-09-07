#include <iostream>
using namespace std;
struct test
{
	int rno;
	int marks[5];
};
int main()
{
	test t;
	int total=0;
	float avg= 0.0;
	cout<<"Enter Roll No: ";
	cin>>t.rno;
	for(int i=0; i<5; i++)
	{
		cout<<"Enter marks for subject "<<i+1<<": ";
		cin>>t.marks[i];
		total = total+t.marks[i];
	}
	avg = total/5.0;
	cout<<"Roll No: "<<t.rno<<endl;
	cout<<"Total marks: "<<total<<endl;
	cout<<"Average: "<<avg<<endl;
	return 0;
}
