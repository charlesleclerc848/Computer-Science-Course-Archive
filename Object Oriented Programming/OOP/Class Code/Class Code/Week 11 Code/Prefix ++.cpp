#include<iostream>
using namespace std;

class Counter{
	int count;
	public:
		Counter(int c){
			count = c;
		}	
		Counter(){
			
		}		
		Counter operator++(){
			Counter temp;
			++count;
			temp.count = count;
			return temp;
		}
		
		Counter operator++(int){
			Counter temp;
			count++;
			temp.count = count;
			return temp;
		}
		
		void display(){
			cout<<"Value of count is "<<count<<endl;
		}
};

int main(){
	Counter c1(3),c2;
	c2 = c1++;
	c2.display();
}







