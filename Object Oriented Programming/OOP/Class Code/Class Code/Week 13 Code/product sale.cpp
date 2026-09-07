#include<iostream>
using namespace std;

class InventoryManagement{
	string message;
	public:
		InventoryManagement(string msg){
			message = msg;
		}
		string what(){
			return message;
		}
};

class SaleProducts{
	int quantity;
	string name;
	int price;
	public:
		SaleProducts(int q, string n, int p){
			quantity = q;
			name = n;
			price = p;
		}	
		void sale(int qq){
			if(qq>quantity){
				throw InventoryManagement("Out of stock for selected product.");
			}
			quantity = quantity - qq;
			cout<<"Product : "<<name<<" quantity : "<<qq<<" total price : "<<price*qq<<endl;\
			cout<<"Remaining quantity of product is :" <<quantity<<endl;
		}
};

int main(){
	SaleProducts p1(300, "Pen", 30);
	try{
		p1.sale(60);
	}
	catch(InventoryManagement i){
		cout<<"Error : "<<i.what();
	}
}














