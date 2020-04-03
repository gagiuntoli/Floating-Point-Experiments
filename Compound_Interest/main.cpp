/*
  
  Ideas taken from:

  a) "Numerical Computing with IEEE FLoating Point Arithmetic" 
     M. Overton

  Program to compound the compound interest rate formula:
  
  Cn(x,n) = (1 + x/n)^n

  Way 1 (comp_int_1) :

     a) z = 1 + x / n    set   w = 1
     b) Repeat (n times) w = w * z 
     
  Way 2 (comp_int_2) :

     a) z = 1 + x / n
     b) Use pow(z,n) from C Standard Library <cmath>
     
  Way 3 (comp_int_3) :

     a) z = 1 + x / n
     b) Cn = z^n => Cn = exp(n log(z)) from the C Standard Library

  Way 4 (comp_int_4) :
  
     a) u = x / n
     b) w = log1p(u) => Cn = exp(n * w)

     The use of log1p(s) = log(1 + s) avoids the initial sum which
     causes the big error which is multiplied after due to the 
     condition number of the algorithm.

 */

#include <iostream>
#include <cmath>
#include <iomanip>      // std::setprecision

using namespace std;

template <typename T>
T comp_int_1(T & x, unsigned long & n)
{
	T z = 1.0 + x / n;
	T w = 1.0;

	for (int i = 0; i < n; i++) {
		w *= z;
	}

	return w;
}

template <typename T>
T comp_int_2(T & x, unsigned long & n)
{
	T z = 1.0 + x / n;
	T w = pow(z, n); 
	return w;
}

template <typename T>
T comp_int_3(T & x, unsigned long & n)
{
	T z = 1.0 + x / n;
	T w = exp(n * log(z)); 
	return w;
}

template <typename T>
T comp_int_4(T & x, unsigned long & n)
{
	T u = x / n;
	T w = log1p(u);
	return exp(n * w);
}

int main()
{

	float xf = 0.05f;
	unsigned long n[] = {4, 365,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
		10000000000,
		100000000000};

	cout  << fixed << setprecision(9) << endl;

	cout << "Simple precision" << endl;
	cout << left << setw(16) << setfill(' ') << "n"
	     << left << setw(16) << setfill(' ') << "Way 1"
	     << left << setw(16) << setfill(' ') << "Way 2"
	     << left << setw(16) << setfill(' ') << "Way 3"
	     << left << setw(16) << setfill(' ') << "Way 4" << endl;

	for (auto &ns : n) {
		cout << left << setw(15) << setfill(' ') << ns << " "
		     << left << setw(15) << setfill(' ') << comp_int_1(xf, ns) << " "
		     << left << setw(15) << setfill(' ') << comp_int_2(xf, ns) << " "
		     << left << setw(15) << setfill(' ') << comp_int_3(xf, ns) << " "
		     << left << setw(15) << setfill(' ') << comp_int_4(xf, ns) << endl;
	}

	double xd = 0.05f;

	cout << endl;
	cout << "Double precision" << endl;
	cout << left << setw(16) << setfill(' ') << "n"
	     << left << setw(16) << setfill(' ') << "Way 1"
	     << left << setw(16) << setfill(' ') << "Way 2"
	     << left << setw(16) << setfill(' ') << "Way 3"
	     << left << setw(16) << setfill(' ') << "Way 4" << endl;

	for (auto &ns : n) {
		cout << left << setw(15) << setfill(' ') << ns << " "
		     << left << setw(15) << setfill(' ') << comp_int_1(xd, ns) << " "
		     << left << setw(15) << setfill(' ') << comp_int_2(xd, ns) << " "
		     << left << setw(15) << setfill(' ') << comp_int_3(xd, ns) << " "
		     << left << setw(15) << setfill(' ') << comp_int_4(xd, ns) << endl;
	}

}
