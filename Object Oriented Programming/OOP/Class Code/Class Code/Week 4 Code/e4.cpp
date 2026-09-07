#include<iostream>
using namespace std;
class Date{
	int day;
	int month;
	int year;
	public:
		Date(){
		}
		Date(int d, int m, int y){
			day = d;
			month = m;
			year = y;
		}
		void display()
		{
			cout<<day<<"/"<<month<<"/"<<year<<endl;
		}
};

int main()
{
	Date * ptr[31];
	
	for(int day=0; day<31; day++)
	{
		ptr[day] = new Date(day+1,3,2024);
	}
	
	for(int day=0; day<31; day++)
	{
		ptr[day]->display();
	}
	
	for(int day=0; day<31; day++)
	{
		delete[] ptr[day];
	}
	
}






