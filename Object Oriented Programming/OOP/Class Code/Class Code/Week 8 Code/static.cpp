#include<iostream>
using namespace std;
class counter{
	
	public:
		static int count;
		int a=5;
		counter(){
			count++;
		}
		void display(){
			cout<<count;
		}
};

int counter::count = 0;

int main(){
//	counter c1,c2,c3;
//	c3.display();
	cout<<counter::a;
}
