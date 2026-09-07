#include<iostream>
using namespace std;
class DeepCopy{
	public:
	int sapID;
	string name;
	int *age;
	
		DeepCopy(int i, string n, int a)
		{
			sapID = i;
			name = n;
			age = new int;
			*age = a;
		}
		
		// Deep copy
		DeepCopy(DeepCopy & d)
		{
			sapID = d.sapID;
			name = d.name;
			age = new int;
			*age = *(d.age);
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
	DeepCopy s1(700, "Ali", 20);
	s1.display();
	
	cout<<"Second Object\n\n";
//	DeepCopy s2=s1;
	DeepCopy s2(s1);
//	*s1.age = 80;
	
	
	delete s1.age;
	s1.display();
	
	s2.display();
	return 0;
}













