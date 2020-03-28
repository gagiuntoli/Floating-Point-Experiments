#include <stdio.h>
#include <stdint.h>

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
};

void print(union ieee784_float f)
{
	printf("Number   : %f\n", f.number);
	printf("Sign     : %d\n", f.parts.sign);
	printf("Exponent : ");

	for (int i = IEEE784_FLOAT_EXPONENT_BITS - 1; i >= 0; i--) {
		printf("%c", (f.parts.exponent & (1 << i)) ? '1' : '0');
	}
	printf(" = %d", f.parts.exponent);

	printf("\n");

	printf("Mantissa : ");
	for (int i = IEEE784_FLOAT_MANTISSA_BITS - 1; i >= 0; i--) {
		printf("%c", (f.parts.mantissa & (1 << i)) ? '1' : '0');
	}
	printf("\n");
}

int main() {

	union ieee784_float f1 = {-1.75f};
	print(f1);

	printf("\n");

	f1.number = 1.75f;
	print(f1);

	return 0;
}
