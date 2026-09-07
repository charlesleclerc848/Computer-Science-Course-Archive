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
		void display(){
			cout<<"Book title is "<<title<<endl;
		}
};

class Library{
	string name;
	Book book[2];
	int bookCount = 0;
	public:
		Library(string n)
		{
			name = n;
		}
		
		void addBook(Book b)
		{
			book[bookCount] = b;
			bookCount++;
		}
		
		void displayLibrary()
		{
			cout<<name<<" has following books\n";
			for(int i=0; i<bookCount; i++)
			{
				book[i].display();
			}
		}
		~Library(){
			cout<<name<<" is destroyed\n";
		}
};

int main(){
	Book b1("C++ Book");
	Book b2("DLD Book");
	Book b3("Discrete Book");
	{
		Library lib1("UOL Library");
		lib1.addBook(b1);
		lib1.addBook(b2);
		lib1.displayLibrary();
	}
	Library lib2("UCP Library");
	lib2.addBook(b1);
	lib2.addBook(b3);
	lib2.displayLibrary();
}










