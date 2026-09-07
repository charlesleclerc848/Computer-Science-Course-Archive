#include<iostream>
using namespace std;
class Book{
	string title;
	public:
		Book (){
		}
		Book(string t)
		{
			title = t;
		}
		void display()
		{
			cout<<title<<endl;
		}
};

class Library{
	string name;
	Book* book[2];
	int bookCount=0;
	
	public:
		Library(string n)
		{
			name = n;
		}
		void displayLibrary()
		{
			cout<<"The library "<<name<<" has following books\n";
			for(int i=0; i<bookCount; i++)
			{
				cout<<"Book Title = ";
				book[i]->display();
			}
		}
		void addBook(Book* b)
		{
			if(bookCount<2)
			{
				book[bookCount] = b;
				bookCount++;
			}
			else
			{
				cout<<"Library is full, no space for new book\n";
			}
		}
		~Library(){
			cout<<"Library destructor called\n";
		}
};

int main(){
	Book b1("C++ Book");
	Book b2("DLD Book");
	Book b3("Discrete Book");
	{
		Library lib1("UOL Library");
		lib1.addBook(&b1);
		lib1.addBook(&b2);
		lib1.addBook(&b3);
		lib1.displayLibrary();
	}
	Library lib2("UCP Library");
	lib2.addBook(&b1);
	lib2.addBook(&b2);
	lib2.displayLibrary();
}








