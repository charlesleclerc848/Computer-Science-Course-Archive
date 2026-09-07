#include <iostream>
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
//if "access modifier" is public, then data member of base class; "public remains public", "protected remains proected" 
class Derived : public Base
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

//main function
int main()
{
	Derived obj1;	
//	obj1.dNum = 7;
//	we can access "BasePublicNum", beacuse access modefier is public
	obj1.BasePublicNum = 0;
//	we can cannot access "BaseProtectedNum", beacuse access modefier is public, so protected remain proteced
//	obj1.BaseProtectedNum=21;
//	cout << "The value of dNum: " << obj1.dNum << endl;
//	cout << "The value of BasePublicNum: " << obj1.BasePublicNum << endl;

//	Error
//	cout << "The value of BaseProtectedNum: " << obj1.BaseProtectedNum << endl;
	obj1.func();		
	return 0;
}

