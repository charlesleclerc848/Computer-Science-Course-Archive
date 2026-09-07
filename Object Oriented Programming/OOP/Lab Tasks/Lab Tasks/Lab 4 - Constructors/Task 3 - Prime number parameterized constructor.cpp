#include<iostream>
using namespace std;

class Prime {
   int number;
   bool isPrime = true;
public:
	// Parameterized Constructor definition
   	Prime(int num) {
		number = num;
		if(num > 1)
		{
	      	{
				for (int i = 2; i <= num / 2; i++){
	            	if (num % i == 0) {
	               		isPrime = false;
	               		break;
	            	}
	            }
	      	}	
		}
		else
		{
			isPrime = false;
		}
   	}
   
   //Member Function show() for display result.
   void show() {
      if (isPrime)
         cout << number << " is a Prime Number.";
      else
         cout << number << " is Not a Prime Number.";
   }
};

int main() {
   int number;
   cout << "Enter the Number:";
   cin>>number;

   // Object Creation For Class and Initiate Value from the user input
   Prime obj(number);

   // Call Member Function show()
   obj.show();
   return 0;
}
