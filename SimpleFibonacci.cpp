#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int a = 0, b = 1, fib;
	
	
	for(int i = 1; i < 25; i++){
		fib = a + b;
		a = b;
		b = fib;
		cout << fib << endl;
	}
	return 0;
}
