#include<iostream>
using namespace std;
class DeepCopy{
	public:
	int a;
	int b;
	int *ptr;
		DeepCopy(int aa, int bb, int pp)
		{
			a = aa;
			b = bb;
			ptr = new int;
			*ptr = pp;
		}
	
		// Deep copy
		DeepCopy(DeepCopy &source)
		{
			a = source.a;
			b = source.b;
			ptr = new int;
			*ptr = *(source.ptr);
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
	DeepCopy s1(5,10,20);
	cout<<"First object\n";
	s1.display();
	
	
	cout<<"Second object\n";
//	DeepCopy s2=s1;
	DeepCopy s2(s1);
	*s1.ptr = 30;
	s1.a = 60;
	s1.display();
	s2.display();
	
	return 0;
}












