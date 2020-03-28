/*

  This program appears in "Numerical Computing with IEEE Floating
  Point Arithmetics" of M. L. Overton.
  
  The program is used to evalute input and output binary and decimal
  conversions.

  The first argument to scanf("...",...) and printf("...",...)  is
  called "Control String", there the "Format Code" is specified.

 */

#include <stdio.h>

int main ()
{
        float x;
	//double x;

/*

  Scanf routine perfoms a convertion from decimal to the binary
  floating point representation storing them in them in memory
  address.

  The Format Codes %f and %e have the same effect in scanf; these
  process data in fixed format (0.666) or exponential format
  (6.66e-1). Check this by running the code and giving does input, the
  output should not change. Also comment the scanf call with with %f
  and uncomment the one with %e to check.
  
  If the variable x is changed to double format, the scanf instruction
  will store the representation of a float (32 bits) in a variable of 
  double format precision (64 bits). This wrong translation can be 
  fixed by changing the Format code to %lf or %le in the Scanf control
  string.

*/
	
	scanf("%f", &x);
	//scanf("%e", &x);

/*

  Printf routine perfoms a convertion from the binary floating point
  representation to decimal and outputs that in the standard output.

  The Format Codes %f and %e have DIFFERENT effects for printf and it
  is important to understand that to avoid precision looses when data
  is output. For example if input 1.0e-10 is given %f would show
  0.000000 and %e would show 1.0e-10.

*/
	
	printf("x (%%f)       = %f\n", x);
	printf("x (%%e)       = %e\n", x);
	printf("x (%%-8.3f)   = %-8.3f\n", x);
	printf("x (%%8.3e)    = %8.3e\n", x);
	printf("x (%%-21.15f) = %-21.15f\n", x);
	printf("x (%%21.15e)  = %21.15e\n", x);

	return 0;
}
