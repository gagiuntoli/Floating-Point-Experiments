/*
  
  Ideas taken from:

  a) "Numerical Computing with IEEE FLoating Point Arithmetic" 
     M. Overton

  Program to compound the Exponential Function
  
 */

#include <iostream>
#include <cmath>
#include <iomanip>  // std::setprecision
#include <chrono>   // for high_resolution_clock

using namespace std;
using namespace std::chrono;

template <typename T>
T Exponential(T x)
{
	bool invert_res = (x < 0);
	x = (x < 0) ? -x : x;
	T sumOld = 0.0, sumNew = 1.0, term = 1.0;
	unsigned n = 0;
	while (sumNew != sumOld) {
		sumOld = sumNew;
		term *= (x / (n++ + 1));
		sumNew = sumOld + term;
	}
	return invert_res ? 1 / sumNew : sumNew;
}

int main()
{
	cout << "x               Exponential     exp (cmath)     Time Exponential  Time exp(cmath)" << endl;

	float resExponential, resExp;

        float xs[] = {-10, -5, -1, 0, 1, 5, 10};

	for (auto &x : xs) {

		auto start1 = high_resolution_clock::now();

		for (int i = 0; i < 10000; i++)
		resExponential = Exponential(x);

		auto finish1 = high_resolution_clock::now();
		auto elapsedExponential = duration_cast<nanoseconds>(finish1 - start1);

		auto start2 = high_resolution_clock::now();

		for (int i = 0; i < 10000; i++)
		resExp = exp(x);

		auto finish2 = high_resolution_clock::now();
		auto elapsedExp = duration_cast<nanoseconds>(finish2 - start2);

		cout << left << fixed << setw(15) << x  << " "
		     << scientific << setw(15) << resExponential << " " 
		     << scientific << setw(15) << resExp << " "
		     << setw(17) << elapsedExponential.count() << " " << elapsedExp.count() << endl;
	}

	return 0;
}
