#include<iostream>
using namespace std;
class Counter{
	public:
	static int count;
	int a =9;
	
		Counter()
		{
			count++;
		}
		
		static int getCount()
		{
			cout<<count;
			return count;
		}
};

int Counter::count=60;

int main()
{
//	Counter c1,c2,c3;
	cout<<Counter::count;
	cout<<Counter::getCount();
}









