#include<iostream>
using namespace std;

class Engine{
	string modelName;
	public:
		Engine(string m)
		{
			modelName = m;
			cout<<"Engine "<<modelName<<" is created\n";
		}
		
		~Engine()
		{
			cout<<"Engine "<<modelName<<" is destroyed\n";
		}
};

class Aeroplane{
	string name;
	Engine *e1;
	public:
		Aeroplane(string n, string ee){
			name = n;
			e1 = new Engine(ee);
		}	
		void start(){
			cout<<"Aeroplane "<<name<<" is starting\n";
		}
		~Aeroplane(){
			delete e1;
			cout<<"Aeroplane "<<name<<" is destroyed\n";
		}
};

int main(){
	Aeroplane a("PIA001", "AX001");
	a.start();
	
	Aeroplane aa("PIA002", "AX002");
	a.start();
}
