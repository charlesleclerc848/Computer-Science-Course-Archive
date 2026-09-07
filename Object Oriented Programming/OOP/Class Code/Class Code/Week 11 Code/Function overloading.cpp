#include<iostream>
using namespace std;
class calculator{
	public:
	void add(int x, int y){
		cout<<"Sum of two numbers is "<<x+y<<endl;
	}
	void add(int x, int y, int z){
		cout<<"Sum of three numbers is "<<x+y+z<<endl;
	}	
	void add(double x, double y){
		cout<<"Sum of two numbers (double) is "<<x+y<<endl;
	}
};

int main(){
	calculator c1,c2,c3;
	c1.add(4,4);
	c2.add(2,2,1);
	c3.add(3.3,4.4);
}