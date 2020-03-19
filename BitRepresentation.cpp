#include <iostream>
#include <cstdint>

using namespace std;

#define IEEE784_FLOAT_SIGN_BITS     1
#define IEEE784_FLOAT_EXPONENT_BITS 8
#define IEEE784_FLOAT_MANTISSA_BITS 23

union ieee784_float {
	float number;
	struct {
		// We assume Little Endian format
		// "Little Bits First"
		unsigned int mantissa : IEEE784_FLOAT_MANTISSA_BITS;
		unsigned int exponent : IEEE784_FLOAT_EXPONENT_BITS;
		unsigned int sign     : IEEE784_FLOAT_SIGN_BITS;
	} parts;

	void print();
};

void ieee784_float::print()
{
	cout << "Number   : " << number << endl
	     << "Sign     : " << parts.sign << endl
	     << "Exponent : ";
		
	for (int i = IEEE784_FLOAT_EXPONENT_BITS - 1; i >= 0; i--) {
		cout << ((parts.exponent & (1 << i)) ? '1' : '0');
	}
	cout << " = " << parts.exponent << endl;
	cout << "Mantissa : ";

	for (int i = IEEE784_FLOAT_MANTISSA_BITS - 1; i >= 0; i--) {
		cout << ((parts.mantissa & (1 << i)) ? '1' : '0');
	}
	cout << endl;
}

int main() {

	ieee784_float f1 = {-1.75f};
	f1.print();

	cout << endl;

	f1 = {1.75f};
	f1.print();

	return 0;
}
