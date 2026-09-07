#include<iostream>
using namespace std;
class add
{
	private:
		int a;
	public:
		void set()
		{
			cout<<"Enter the integer : ";
			cin>>a;
		}
		
		add operator +(add &p)
		{
			add temp;
			temp.a = a + p.a;
			return temp;
		}
		
		add operator -(add &o)
		{
			add result;
			result.a = a - o.a;
			return result;
		}
		
		void output()
		{
			cout<<"Expression b+c-e result is = : "<<a;
		}
};
int main()
{
	add b,c,d,e;
	b.set();
	c.set();
	e.set();
	d=b+c;
	d=d-e;
	d.output();
}

