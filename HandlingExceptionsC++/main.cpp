
#include <fenv.h>
#include <iostream>

#pragma STDC FENV_ACCESS on

using namespace std;

float divide(float x, float y)
{
	fenv_t envp;
	
	float ans = x / y;
	if (fetestexcept(FE_ALL_EXCEPT)) {
		cout << "Exception raised" << endl;
	}

	feholdexcept(&envp);
	if (!fetestexcept(FE_ALL_EXCEPT)) {
		cout << "No exception raised" << endl;
	}

	  // clears exception 
	//feclearexcept(FE_OVERFLOW | FE_DIVBYZERO); 

	return ans;
}


int main()
{
	feclearexcept(FE_ALL_EXCEPT);
	float x = 1.0;
	float y = 0.0;

	float div = divide(x, y);
	cout << div << endl;

	if (!fetestexcept(FE_ALL_EXCEPT)) {
		cout << "No exception raised" << endl;
	}
}
