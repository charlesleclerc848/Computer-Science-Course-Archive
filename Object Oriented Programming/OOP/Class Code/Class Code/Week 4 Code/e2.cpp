#include<iostream>
using namespace std;
class Person{
	int age;
	string name;
	public:
//		Person(){
//			
//		}
		Person(int a, string n) : age{a}, name{n}
		{
			
		}
		void display()
		{
			cout<<"Age of person = "<<age<<endl;
			cout<<"Name of person = "<<name<<endl;
		}
};

int main()
{
	Person p[3] = {
		Person(22,"Ali"),
		Person(12,"Ali Zaib"),
		Person(32,"Ali Khan")	
	};
//	int age;
//	string name;
//	for (int i=0; i<3; i++)
//	{
//		cout<<"Enter name : ";
//		cin>>name;
//		cout<<"Enter age : ";
//		cin>>age;
//		
//		p[i] = Person(age, name);
//	}
	for (int i=0; i<3; i++)
	{
		p[i].display();
	}
}










