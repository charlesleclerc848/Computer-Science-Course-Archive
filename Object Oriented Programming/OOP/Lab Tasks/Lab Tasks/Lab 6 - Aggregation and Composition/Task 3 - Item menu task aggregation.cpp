#include<iostream>
using namespace std;

class item{
	int id;
	string name;
	public:
		item(){
		}
		item(int i, string n){
			id = i;
			name = n;
		}
		void displayItem(){
			cout<<"ID = "<<id<<endl;
			cout<<"Name = "<<name<<endl;
		}
};



class menu{
	string menuname;
	item items[5];
	int count = 0;
	public:
		menu(string m){
			menuname = m;
		}
		void addItem(item i){
			items[count] = i;
			count++;
		}
		void displayMenu(){
			cout<<"Menu name = "<<menuname<<endl;
			for(int i =0; i<count; i++){
				items[i].displayItem();
			}
		}
		~menu(){
			cout<<"Menu destructor called\n";
		}
};

int main(){
	item i1(1,"Pizza");
	item i2(2,"Burger");
	item i3(3,"Sanwich");
	{
		menu m1("Menu for Fast Food");
		m1.addItem(i1);
		m1.addItem(i2);
		m1.addItem(i3);
		m1.displayMenu();
	}
	menu m2("New Menu for Fast Food");
	m2.addItem(i1);
	m2.addItem(i2);
	m2.addItem(i3);
	m2.displayMenu();
}





