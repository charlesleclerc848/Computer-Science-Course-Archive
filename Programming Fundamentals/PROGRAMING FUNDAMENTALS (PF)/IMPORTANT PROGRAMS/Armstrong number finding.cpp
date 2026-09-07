#include <iostream>
#include <cmath>
using namespace std;

int main() {
   int num, originalNum, remainder, result = 0, n = 0;

   cout << "Enter a positive integer: ";
   cin >> num;

   originalNum = num;

   // store the number of digits in n
   for (originalNum; originalNum != 0; ++n) {
       originalNum /= 10;
   }

   originalNum = num;

   // calculate the sum of each digit raised to the power of n
   while (originalNum != 0) {
       remainder = originalNum % 10;
	   result += pow(remainder, n);
       originalNum /= 10;
   }

   // check if the number is Armstrong or not
   if (result == num) {
       cout << num << " is an Armstrong number." << endl;
   }
   else {
       cout << num << " is not an Armstrong number." << endl;
   }

   return 0;
}

