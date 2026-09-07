#include<iostream>
using namespace std;

int main()
{
	int sapID;
	string name;
	
	cout<<"Enter your SAP ID = ";
	cin>>sapID;
	cin.ignore();
	
	cout<<"Enter your name = ";
	getline(cin,name);
	
	//cin>>name;
	cout<<"Your name is = "<<name;
}
