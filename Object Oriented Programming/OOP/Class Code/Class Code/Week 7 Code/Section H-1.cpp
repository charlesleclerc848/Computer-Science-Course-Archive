#include<iostream>
using namespace std;
class Base{
	private:
		int privateBaseNum;
	protected:
		int protectedBaseNum;
	public:
		int publicBaseNum;
	
};

class Child:protected Base{
	public:
		void setValue(){
			protectedBaseNum = 5;
			publicBaseNum = 10;
//			privateBaseNum = 15;
		}
		void show()
		{
			cout<<"protectedBaseNum = "<<protectedBaseNum<<endl;
			cout<<"publicBaseNum = "<<publicBaseNum<<endl;
		}
};

class grandChild:public Child{
	public:
		void display(){
			cout<<"protectedBaseNum = "<<protectedBaseNum<<endl;
		}
};

int main()
{
	Child c;
//	c.publicBaseNum=30;
	c.setValue();
	c.show();

}
