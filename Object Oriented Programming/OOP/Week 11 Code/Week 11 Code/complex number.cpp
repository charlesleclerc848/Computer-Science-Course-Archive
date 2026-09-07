#include<iostream>
using namespace std;

class Complex{
	int real, imag;
	
	public:
		Complex(){
		}
		Complex(int r, int i){
			real = r;
			imag = i;
		}
		
		Complex operator +(Complex &old){
			Complex c3;
			c3.real = real + old.real;
			c3.imag = imag + old.imag;
			return c3;
		}
		
		void display(){
			cout<<real<<" i"<<imag<<endl;
		}
		
		void operator -(Complex &old){
			cout<<real-old.real<<" i"<<imag-old.imag<<endl;
		}
};

int main(){
	Complex c1(5, 3), c2(2, 9);
//	c1.operator-(c2);
	c1-c2;

	Complex result = c1 + c2;
	result.display();
}








