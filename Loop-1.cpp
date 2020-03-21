/*
  
  This program initializes a float variable x in 1 and performs
  succesives divisions by 2 of that number.

  In the first 126 divisions the number is a IEEE single normalized
  number.  After the 126th division, since the system supports IEEE
  single subnormal numbers, the division continues up to 1.401298e-45.

 */

#include <iostream>
#include <iomanip>
#include "myfloat.hpp"

using namespace std;

int main()
{
	float x = {1.0f};
	unsigned int n = {0u};

	cout ;	

	while (x > 0.0f) {
		x /= 2;
		n ++;

		FloatingPoint<float> x2(x);

		cout << "2^(-" << setfill('0') << setw(3) << n
		     << ") = " << scientific << x << " = ";

		// Print IEEE binary representation
		x2.print();

		cout << endl;
	}

	return 0;
}
