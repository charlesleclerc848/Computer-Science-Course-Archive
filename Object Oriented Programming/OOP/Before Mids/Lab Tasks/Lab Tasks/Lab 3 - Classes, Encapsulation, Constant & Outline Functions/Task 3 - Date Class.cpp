#include<iostream>
using namespace std;

class Date
{
	private:
		int year,month,day;
	
	public:
		void setDate( )
		{
			cout<<"Enter Year : ";
			cin>>year;
			cout<<"Enter Month : ";
			cin>>month;
			cout<<"Enter Date : ";
			cin>>day;
	 	}	//end of setDate
	
	 	void printDate()
	 	{
	  		cout<<"Today Date is......"<<day<<"/"<<month<<"/"<<year;
	 	}	//end of printDate
}; //end of Date class

int main()
{
	Date d;
	d.setDate();
	d.printDate();
}

