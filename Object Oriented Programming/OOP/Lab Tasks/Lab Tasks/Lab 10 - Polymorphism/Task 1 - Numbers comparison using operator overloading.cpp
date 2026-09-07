#include<iostream>
using namespace std;

class Number 
{
	private: 
		float num;
 	public:
		void input()
		{
			cout<<"Enter Number : "; 
			cin>>num;	  
		}
		int operator ==(Number &n)
		{ 
			if(num == n.num)
				return 1;
			else
				return 0;
		}
		void show() 
		{
			cout<<num<<endl; 
		} 
};

int main()
{
	Number n1,n2;
	n1.input();
	n2.input();
	if(n1 == n2)
		cout<<"\nNumbers are equal\n";
	else
		cout<<"\nNumbers are not equal\n";
	cout<<"\nFirst number was : ";
	n1.show();
	cout<<"Second number was : ";
	n2.show();
}

