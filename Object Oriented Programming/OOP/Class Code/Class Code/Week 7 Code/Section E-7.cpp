#include<iostream>
using namespace std;
class Publication{
	protected:
		string title, publisher;
	public:
		Publication(string t, string p)
		{
			title = t;
			publisher = p;
		}
		void display()
		{
			cout<<"Title = "<<title<<endl;
			cout<<"Publisher = "<<publisher<<endl;
		}
};

class Book:public Publication{
	int pageCount;
	public:
		Book(int pc, string tt, string pp):Publication(tt,pp)
		{
			pageCount = pc;
		}
		void showPageCount(){
			cout<<"Page Count = "<<pageCount<<endl;
		}
};

class Magazine:public Book{
	int issueNo;
	public:
		Magazine(int i_no, int pcc, string t, string p):Book(pcc,t,p)
		{
			issueNo = i_no;
		}
		void showIssueNo(){
			cout<<"Issue No = "<<issueNo<<endl;
			showPageCount();
			display();
		}
};

int main()
{
	Magazine m(1001, 3000, "OOP", "Ali");
	m.showIssueNo();
}







