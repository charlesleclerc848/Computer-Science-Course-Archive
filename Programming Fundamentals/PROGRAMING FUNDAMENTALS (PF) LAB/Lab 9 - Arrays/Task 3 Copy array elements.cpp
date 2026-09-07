#include<iostream>
using namespace std;
int main() {
	int A[] = {99,89,79,69,59};
	int B[5],i;
	for (i = 0; i < 5; i++)
		B[i] = A[i];
	for (i = 0; i < 5; i++)
		cout<<"A["<<i<<"] = " <<A[i]<<", ";
	cout<<endl;
	for (i = 0; i < 5; i++)
		cout<<"B["<<i<<"] = " <<B[i]<<", ";
	return 0;
}
