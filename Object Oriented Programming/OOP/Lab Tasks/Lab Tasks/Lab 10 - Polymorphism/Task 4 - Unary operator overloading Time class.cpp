#include<iostream>
using namespace std;

class Time
{
	private: 
		int hours, minutes, seconds;
 	public:
		Time(int h, int m, int s)	
		{
			hours = h;
			minutes = m;
			seconds = s;	
		}
		void show()
		{
			cout<<hours<<":"<<minutes<<":"<<seconds;
		}
	 	void operator ++()
		{ 	
			++minutes;	
		}
		void operator --()
		{ 	
			--seconds;	
		}
}; 
int main()
{ 
	Time t(3,34,56);
	cout<<"Initial Time = ";
	t.show();
    ++t;
    --t;
	cout<<"\n\nTime After Operator Overloading = ";
    t.show();
}


