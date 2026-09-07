#include<iostream>
using namespace std;
class Base
{
	public:
		int BasePublicNum;
	protected:
		int BaseProtectedNum;
	private:
		int BasePrivateNum;
};
//if "access modifier" is private, then data member of base class; "public becomes private", "protected becomes private" 
class Derived : private Base
{
	public:
	int dNum;
	Derived()
	{
		BasePublicNum = 1;
		BaseProtectedNum = 2;
//		BasePrivateNum = 3;
	}
	void func() 
	{
		cout << "The value of BasePublicNum: " << BasePublicNum<<endl;
    	cout << "The value of BaseProtectedNum: " << BaseProtectedNum;
	}
};
//as Derived class was inherited private, so BasePublicNum aslo become private. that it is why it cannot access here 
class grandChild : public Derived
{
	public:
	int gCNum;
	grandChild()
	{
		dNum=0;
//		BasePublicNum = 3;
//		BaseProtectedNum = 4;
//		BasePrivateNum = 3;
	}
	void funGrandChild() 
	{
//		cout << "The value of BasePublicNum: " << BasePublicNum<<endl;
//    	cout << "The value of BaseProtectedNum: " << BaseProtectedNum;
	}
};



//main function
int main()
{
		Derived obj1;	
		obj1.dNum = 7;
		
//		we cannot access "BasePublicNum", beacuse access modefier is private
//		obj1.BasePublicNum = 0;
//		we can cannot access "BaseProtectedNum", beacuse access modefier is private
//		obj1.BaseProtectedNum=21;
		cout << "The value of dNum: " << obj1.dNum << endl;
// Error
//		cout << "The value of BasePublicNum: " << obj1.BasePublicNum << endl;

//	Error
//		cout << "The value of BaseProtectedNum: " << obj1.BaseProtectedNum << endl;

		grandChild objChild;
		objChild.funGrandChild();	
		return 0;
}

