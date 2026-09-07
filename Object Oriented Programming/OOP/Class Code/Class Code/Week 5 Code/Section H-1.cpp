#include<iostream>
using namespace std;
class Student{
	public:
	int sapID;
	string name;
	int *age;
	
		Student(int i, string n, int a)
		{
			sapID = i;
			name = n;
			age = new int;
			*age = a;
		}
		void display()
		{
			cout<<"SAP ID = "<<sapID<<endl;
			cout<<"Name = "<<name<<endl;
			cout<<"Age = "<<*age<<endl;
		}
};

int main()
{
	Student s1(700, "Ali", 20);
	s1.display();
	
	cout<<"Second Object\n\n";
//	Student s2=s1;
	
	Student s2(s1);
	*s1.age = 80;
	s1.display();
	
	delete s1.age;
	
	s2.display();
	return 0;
}













