/*

  Template to understand the IEEE Floating Point representation.
  
  ------------------------

  Single Precision:

  Sign  =  1 bit
  Exponent = 8 bits
  Mantissa = 24 bits (23 explicity stored) 

  ------------------------

  Double Precision

  Sign  =  1 bit
  Exponent = 11 bits
  Mantissa = 53 bits (52 explicity stored) 
  
  ------------------------
  
  Assumptions:

  a) Little Endian System

*/

#include <iostream>

using namespace std;

#define IEEE854_SINGLE_SIGN      1
#define IEEE854_SINGLE_EXPONENT  8
#define IEEE854_SINGLE_MANTISSA  23

#define IEEE854_DOUBLE_SIGN      1
#define IEEE854_DOUBLE_EXPONENT  11
#define IEEE854_DOUBLE_MANTISSA  52

template <typename T>
union FloatingPoint {

		
	static constexpr unsigned ieee854_mantissa = (sizeof(T) == 4) ?
		IEEE854_SINGLE_MANTISSA : IEEE854_DOUBLE_MANTISSA;
	static constexpr unsigned ieee854_exponent = (sizeof(T) == 4) ?
		IEEE854_SINGLE_EXPONENT : IEEE854_DOUBLE_EXPONENT;
	static constexpr unsigned ieee854_sign     = (sizeof(T) == 4) ?
		IEEE854_SINGLE_SIGN     : IEEE854_DOUBLE_SIGN;

	T number;	
	struct {
		unsigned long int mantissa : ieee854_mantissa;
		unsigned long int exponent : ieee854_exponent;
		unsigned long int sign     : ieee854_sign;
	} parts;

public:

	FloatingPoint (T _number) {number = _number;}

	void print ();
};


template <typename T>
void FloatingPoint<T>::print ()
{
	cout << parts.sign << " ";

	for (int i = ieee854_exponent - 1; i >= 0; i--) {
		cout << ((parts.exponent & (1 << i)) ? '1' : '0');
	}
	cout << " ";

	for (int i = ieee854_mantissa - 1; i >= 0; i--) {
		cout << ((parts.mantissa & (1 << i)) ? '1' : '0');
	}
}
