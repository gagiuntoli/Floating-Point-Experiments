/*
  Program to show the binary representation of a floating point number
*/

#include "myfloat.hpp"

int main() {

	FloatingPoint<float> f1(-1.75f);
	f1.print();

	cout << endl;

	f1 = {1.75f};
	f1.print();

	cout << endl;

	return 0;
}
