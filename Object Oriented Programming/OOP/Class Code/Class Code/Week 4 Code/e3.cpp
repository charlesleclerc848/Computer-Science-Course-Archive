#include<iostream>
using namespace std;
class Student{
	int age;
	int sapID;
	string name;
	public:
		Student(){
		}
		Student(int a, int s, string n){
			age = a;
			sapID = s;
			name = n;
		}
		void display()
		{
			cout<<"\nStudent name : "<<name;
			cout<<"\nStudent age : "<<age;
			cout<<"\nStudent sapID : "<<sapID;
		}
};

int main()
{
//	Student *ptr = new Student[3];
//	
//	ptr[0] = Student(21,700000, "Ali");
//	ptr[1] = Student(28,7007777, "Ali Zaib");
//	ptr[2] = Student(23,70333, "Ali Khan");

	Student *ptr = new Student[3] {
        Student(21,700000, "Ali"),
        Student(28,7007777, "Ali Zaib"),
        Student(23,70333, "Ali Khan")
    };
	
	for(int i=0; i<3; i++)
	{
		(ptr+i)->display();
	}
	
	delete[] ptr;
	
}











