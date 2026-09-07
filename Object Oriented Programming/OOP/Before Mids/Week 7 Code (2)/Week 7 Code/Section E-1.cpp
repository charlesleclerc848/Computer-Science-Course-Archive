#include<iostream>
using namespace std;

class Base{
	private:
		int basePrivateNum=0;
	protected:
		int baseProtectedNum=0;
	public:
		int basePublicNum=0;
};

class Child : private Base{

//	basePublicNum = 10;
//	baseProtectedNum = 5;
	public:
		void setValue(){
			basePublicNum = 10;
			baseProtectedNum = 5;
		}
		void show()
		{
			cout<<"basePublicNum = "<<basePublicNum<<endl;
			cout<<"baseProtectedNum = "<<baseProtectedNum<<endl;
		}
};


int main()
{
	Child c1;
//	c1.basePublicNum=100;
	c1.setValue();
	c1.show();
}





