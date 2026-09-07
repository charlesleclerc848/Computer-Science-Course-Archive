#include<iostream>
using namespace std;

class Shape{
	public:
		virtual void area(){
			cout<<"Calculating area from base"<<endl;
		}
};

class Rectangle:public Shape{
	int length, width;
	public:
		Rectangle(int l, int w){
			length = l;
			width = w;
		}
		
		void area() override{
			cout<<"Area of rectange is "<<length*width<<endl;
		}
};

class Circle:public Shape{
	int radius;
	public:
		Circle(int r){
			radius = r;
		}
		
		void area() override{
			cout<<"Area of circle is "<<3.14*radius*radius<<endl;
		}
};
int main(){
	Shape *s;
	Rectangle r(3,4);
	Circle c(4);
	
	s = &r;
	s->area();
	
	s = &c;
	s->area();
	
}






