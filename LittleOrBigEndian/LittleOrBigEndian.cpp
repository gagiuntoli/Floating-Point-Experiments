/*

  Program to know if the system uses Big-endian or Little Endian

*/

#include <iostream>
#include <iomanip> // we use it to adjust the output format

using namespace std;

int main()
{
	unsigned int num = 0x01234567;
	char *cp = (char *)&num;

	cout << "The number 0x01234567 is represented in memory as: ";

	for (int i = 0; i < 4; i++) {
		cout << setfill('0') << setw(2) << right << hex
		     << (unsigned int)cp[i] << " ";
	}

	cout << endl;
	cout << ((cp[0] == 0x67) ? "Little Endian" : "Big Endian") << endl;
	return 0;
}
