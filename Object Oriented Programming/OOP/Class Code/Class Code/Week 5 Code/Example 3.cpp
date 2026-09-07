#include<iostream>
using namespace std;
class Counter{
	public:
	static int count;
	static int a;
		Counter()
		{
			count++;	
		}
		
		static int getCount()
		{
			cout<<a;
			return count;
		}
};

int Counter::count=0;
int Counter::a=50;
int main()
{
//	Counter c1,c2,c3;
	
	cout<<Counter::count<<endl;
	cout<<Counter::getCount();
	return 0;
}












