#include <iostream>

using namespace std;

int main()
{
	double a[10] = {};
	double b[10] = {};
	double c = {};

	for (int i = 0; i < 10; i++) {
		c += a[i] * b[i];
	}

	cout << "main_2: This program does 20 double FPOs" << endl;

	return 0;
}
