#include <iostream>
#include <cfenv>

using namespace std;

int main()
{
	size_t short_int_size = sizeof(short int);
	size_t int_size = sizeof(int);
	size_t long_int_size = sizeof(long int);
	size_t long_long_int_size = sizeof(long long int);
	size_t pointer_size = sizeof(int *);

	cout << endl;
	cout << "int_size           : " << int_size << endl;
	cout << "long_int_size      : " << long_int_size << endl;
	cout << "pointer_size       : " << pointer_size << endl;
	cout << "long_long_int_size : " << long_long_int_size << endl;
	cout << endl;

	if (int_size == 2 && long_int_size == 4 && pointer_size == 4) {
		cout << "It seems you have a LP64 or 2/4/4 system (32 bits)"
		     << "-> Win16 API." << endl;
	} else if (int_size == 4 && long_int_size == 4 && pointer_size == 4) {
		cout << "It seems you have a LP64 or 4/8/8 system (32 bits)"
		     << "-> Win32 API, Unix or Unix-like." << endl;
	} else if (int_size == 4 && long_int_size == 4 && pointer_size == 8) {
		cout << "It seems you have a LP64 or 4/8/8 system (64 bits)"
		     << "-> Win64 API" << endl;
	} else if (int_size == 4 && long_int_size == 8 && pointer_size == 8) {
		cout << "It seems you have a LP64 or 4/8/8 system (64 bits)"
		     << "-> Unix or Unix-like." << endl;
	}
	cout << endl;

	cout << "Rounding Mode : ";

	switch (fegetround()) {
	case FE_DOWNWARD:
		cout << "downward" << endl;
		break;
	case FE_TONEAREST:
		cout << "to-nearest" << endl;
		break;
	case FE_TOWARDZERO:
		cout << "toward-zero" << endl;
		break;
	case FE_UPWARD:
		cout << "Upward" << endl;
		break;
	default:
		cout << "Unknown" << endl;
	}

	return 0;
}
