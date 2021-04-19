#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Please give a number as 1st variable: ";
	cin >> a;
	cout << "Please give a number as 2nd variable: ";
	cin >> b;
	
	a = a+b;
	b = a - b;
	a = a-b;
	
	cout << "The value of the 1st variable: " << a << endl; 
	cout << "The value of the 2st variable: " << b << endl;	

	return 0;
}