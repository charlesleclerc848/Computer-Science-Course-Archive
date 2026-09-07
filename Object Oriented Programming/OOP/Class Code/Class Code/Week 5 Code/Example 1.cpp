#include<iostream>
using namespace std;
class Shallow{
	public:
	int a;
	int b;
	int *ptr;
	
	
		Shallow(int aa, int bb, int pp)
		{
			a = aa;
			b = bb;
			ptr = new int;
			*ptr = pp;
		}
		void display()
		{
			cout<<"A = "<<a<<endl;
			cout<<"B = "<<b<<endl;
			cout<<"PTR = "<<*ptr<<endl;
		}
};

int main()
{
	Shallow s1(5,10,20);
	cout<<"First object\n";
	s1.display();
	
	
	cout<<"Second object\n";
//	Shallow s2=s1;
	Shallow s2(s1);
	*s1.ptr = 30;
	s1.display();
	s2.display();
	
	return 0;
}












