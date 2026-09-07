#include<iostream>
using namespace std;

class person
{
	private:
		char name[25];
		char city[20];
		int age;

	public:
		void input()
		{
			cout<<"The name of Person : ";
			cin.getline(name,25);
			cout<<"The age of Person : ";
			cin>>age;
			cout<<"The City of Person : ";
			cin.ignore();
			cin.getline(city,20);
		}

		int getage()
		{
			return age;
		}
		
		void display()
		{
			cout<<"Following are the details of elder person:\n\n";
			cout<<"Name of elder person : "<<name<<endl;
			cout<<"Age of elder person : "<<age<<endl;
			cout<<"City of elder person : "<<city<<endl;
		}
};

int main()
{
	cout<<"Enter details of first person \n\n";
	person p1,p2;
	int age1,age2;

	p1.input();
	cout<<endl;
	cout<<"Enter details of Second person \n\n";
	p2.input();
	cout<<endl;
	age1=p1.getage();
	age2=p2.getage();
	
	if(age1>age2)
	{
		p1. display();
	}
	else if(age1<age2)
	{
		p2.display();
	}
	else
	{
		cout<<"Both persons have same age...!";
	}
}
