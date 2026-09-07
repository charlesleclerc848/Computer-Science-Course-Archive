#include<iostream>
using namespace std;

class Publication{
	protected:
		string title, publisher;
	public:
		Publication(string t, string p){
			title = t;
			publisher = p;
		}
		void displayPublisher(){
			cout<<"Title = "<<title<<endl;
			cout<<"Publisher = "<<publisher<<endl;
		}
};

class Book:public Publication{
	int pageCount;
	public:
		Book(int pc, string t, string p):Publication(t, p)
		{
			pageCount = pc;
		}
		void displayPageCount(){
			cout<<"Page Count = "<<pageCount<<endl;
		}
};

class Magazine:public Book{
	int issueNo;
	public:
		Magazine(int issNo, int pc, string t, string p):Book(pc, t, p)
		{
			issueNo = issNo;
		}
		void displayMagazine(){
			displayPublisher();
			displayPageCount();
			cout<<"Issue No = "<<issueNo;
		}
};

int main(){
	Magazine m(1001, 300, "OOP", "UOL");
	m.displayMagazine();
}










