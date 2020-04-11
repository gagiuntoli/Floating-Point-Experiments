#include <iostream>

using namespace std;

int main()
{
	double a[10] = {};
	double b[10] = {};
	double c = {};
	float d[10] = {};
	float e[10] = {};
	float f = {};

	for (int i = 0; i < 10; i++) {
		c += a[i] * b[i];
	}

	for (int i = 0; i < 10; i++) {
		f += d[i] * e[i];
	}

	cout << "main_3: This program does 20 single FPOs and 20 double FPOs" << endl;

	return 0;
}
